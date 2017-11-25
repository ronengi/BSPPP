#include "std_lib_facilities.h"


const char number = '8';
const char quit = 'q';
const char print = ';';
const char name = 'a';
const char let = 'L';
const char assign = '=';
const string prompt = "> ";
const string result = "= ";
const string declkey = "let";


/*******************************************************************************
 ******************************************************************************/
class Variable {
public:
    string name;
    double value;
};

/*******************************************************************************
 ******************************************************************************/
vector<Variable> var_table;

/*******************************************************************************
 * Return the value of a variable named s
 ******************************************************************************/
double get_value(string s) {
    for (const Variable& v : var_table) {
        if (v.name == s)
            return v.value;
    }
    stringstream err;
    err << "get: undefined variable: '" << s << "'";
    error(err.str());
    return 0.0;
}



/*******************************************************************************
 * Set the value named s to d
 ******************************************************************************/
void set_value(string s, double d) {
    for (Variable& v : var_table) {
        if (v.name == s) {
            v.value = d;
            return;
        }
    }
    stringstream err;
    err << "set: undefined variable: '" << s << "'";
    error(err.str());
}

/*******************************************************************************
 * Is var already in var_table ?
 ******************************************************************************/
bool is_declared(string var) {
    for (const Variable& v : var_table) {
        if (v.name == var)
            return true;
    }
    return false;
}

/*******************************************************************************
 ******************************************************************************/
/* Add {var, val} to var_table */
double define_name(string var, double val) {
    if (is_declared(var)) {
    stringstream err;
    err << "'" << var << "' declared twice";
        error(err.str());
    }
    var_table.push_back(Variable{var, val});
    return val;
}

/*******************************************************************************
 ******************************************************************************/
class Token {
public:
    char kind;
    double value;
    string name;
    Token(char ch) :kind(ch), value(0) { }                  // initialize kind
    Token(char ch, double val) :kind(ch), value(val) { }    // initialize kind and value
    Token(char ch, string n) :kind(ch), name(n) { }         // initialize kind and name
};

/*******************************************************************************
 ******************************************************************************/
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

/*******************************************************************************
 ******************************************************************************/
Token_stream::Token_stream()
: full(false), buffer(0) {
}

/*******************************************************************************
 ******************************************************************************/
void Token_stream::putback(Token t) {
    if (full)
        error("putback() into a full buffer");
    buffer = t;
    full = true;
}

/*******************************************************************************
 ******************************************************************************/
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
        case assign:
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
            char ch1 = ch;
            if (isalpha(ch)) {      // a letter followed by a sequence of letters and digits
                string s;
                s += ch;
                while (cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                    s += ch;
                cin.putback(ch);
                if (s == declkey)       // declaration keyword
                    return Token(let);
                return Token{name, s};
            }
            stringstream err;
            err << "bad token: '" << ch1 << "'";
            error(err.str());
    }
}

/*******************************************************************************
 ******************************************************************************/
void Token_stream::ignore(char c) {
    if (full && c == buffer.kind) {
        full = false;
        return;
    }
    full = false;

    char ch = 0;
    while (cin >> ch) {
        if (c == ch)
            return;
    }
}

/*******************************************************************************
 ******************************************************************************/
Token_stream ts;

/*******************************************************************************
 ******************************************************************************/
double expression();

/*******************************************************************************
 ******************************************************************************/
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
        case name:
            return get_value(t.name);
        case '-':
            return - primary();
        case '+':
            return primary();
        default:
            error("primary expected");
    }
}

/*******************************************************************************
 ******************************************************************************/
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

/*******************************************************************************
 ******************************************************************************/
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

/*******************************************************************************
 ******************************************************************************/
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

/*******************************************************************************
 ******************************************************************************/
double declaration() {
    // assume we have seen "let"
    // handle: name = expression
    // declare a variable called "name" with the initial value "expression"
    Token t = ts.get();
    if (t.kind != name)
        error("name expected in declaration");
    string var_name = t.name;
    Token t2 = ts.get();
    if (t2.kind != assign) {
        stringstream err;
        err << "'" << assign << "' missing in declaration of: '" << var_name << "'";
        error(err.str());
    }

    double d = expression();
    define_name(var_name, d);
    return d;
}

/*******************************************************************************
 ******************************************************************************/
double statement() {
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        default:
            ts.putback(t);
            return expression();
    }
}

/*******************************************************************************
 ******************************************************************************/
void calculate() {
    while (cin) {
        try {
            cout << prompt;
            Token t = ts.get();
            while (t.kind == print)
                t = ts.get();       // consume all "prints"
            if (t.kind == quit)
                return;             // quit
            ts.putback(t);
            cout << result << statement() << "\n";
        }
        catch (exception& e) {
            cerr << "exception: " << e.what() << "\n";
            ts.ignore(print);       // clean up mess
        }
    }
}


/*******************************************************************************
 ******************************************************************************/
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

