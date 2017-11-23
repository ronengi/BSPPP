#include "std_lib_facilities.h"


const char number = '8';
const char quit = 'q';
const char print = '=';
const string prompt = "> ";
const string result = "= ";


class Token {
public:
    char kind;
    double value;

    Token(char ch)
    : kind(ch), value(0) {
    }

    Token(char ch, double val)
    : kind(ch), value(val) {
    }
};

//----------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);      // put a Token back
    void ignore(char c);        // discard characters up to and including a c
private:
    bool full{false};
    Token buffer;
};

//----------------------------------------------------------------------------------

Token_stream::Token_stream()
: full(false), buffer(0) {
}

//----------------------------------------------------------------------------------

void Token_stream::putback(Token t) {
    if (full)
        error("putback() into a full buffer");
    buffer = t;
    full = true;
}

//----------------------------------------------------------------------------------

Token Token_stream::get() {
    if (full) {
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch) {
        case quit:
        case print:
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '!':
            return Token{ch};
        case '.':
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
        {
            cin.putback(ch);
            double val;
            cin >> val;
            return Token{number, val};
        }
        default:
            error("bad token");
    }
}

//----------------------------------------------------------------------------------

void Token_stream::ignore(char c) {
    // TODO: continue here from p.273
}

//----------------------------------------------------------------------------------

Token_stream ts;

//----------------------------------------------------------------------------------

double expression();

//----------------------------------------------------------------------------------

double primary() {
    Token t = ts.get();
    switch (t.kind) {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
        case number: // represents a number
            return t.value;
        case '-':
            return - primary();
        case '+':
            return primary();
        default:
            error("primary expected");
    }
}

//----------------------------------------------------------------------------------

double factorial() {
    double left = primary();
    Token t = ts.get();
    while (true) {
	switch (t.kind) {
	    case '!':
	    {
		int fac = left, res = 1;
		while (fac > 0) {
		    res *= fac;
		    --fac;
		}
		left = res;
		t =ts.get();
		break;
	    }
	    default:
		ts.putback(t);
		return left;
	}
    }
}

//----------------------------------------------------------------------------------

double term() {
    double left = factorial();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '*':
                left *= factorial();
                t = ts.get();
                break;
            case '/':
            {
                double d = factorial();
                if (d == 0) error("division by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%':
            {
                double d = factorial();
                if (d == 0) error("%: divide by zero");
                left = fmod(left, d);
                t = ts.get();
                break;
            }
            default:
                ts.putback(t);
                return left;
        }
    }
}

//----------------------------------------------------------------------------------

double expression() {
    double left = term();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '+':
                left += term();
                t = ts.get();
                break;
            case '-':
                left -= term();
                t = ts.get();
                break;
            default:
                ts.putback(t);
                return left;
        }
    }
}

//----------------------------------------------------------------------------------

void calculate() {
        while (cin) {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get();
            if (t.kind == quit)
                return 0;
            ts.putback(t);
            cout << result << expression() << "\n";
        }
}

//----------------------------------------------------------------------------------

int main() {
    try {
        calculate();
        return 0;
    }
    catch (runtime_error& e) {
        cerr << "runtime_error: " << e.what() << "\n";
        return 1;
    }
    catch (exception& e) {
        cerr << "exception: " << e.what() << "\n";
        return 1;
    }
    catch (...) {
        cerr << "exception \n";
        return 2;
    }

    return 0;
}

