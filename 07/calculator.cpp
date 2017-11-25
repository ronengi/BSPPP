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
    bool full();
    void ignore(char c);        // discard characters up to and including a c
private:
    vector<Token> buffer;
};

/*******************************************************************************
 ******************************************************************************/
Token_stream::Token_stream() { }

/*******************************************************************************
 ******************************************************************************/
void Token_stream::putback(Token t) {
    // if (full())
    //     error("putback() into a full buffer");
    buffer.push_back(t);
    // full = true;
}

/*******************************************************************************
 ******************************************************************************/
Token Token_stream::get() {
    if (full()) {
        // full = false;
        Token t = buffer[buffer.size() - 1];
        buffer.pop_back();
        return t;
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
    while (full() && c != buffer.back().kind)
        buffer.pop_back();
    if (full()) {           // c is found in buffer
        buffer.pop_back();
        return;
    }
    char ch = 0;
    while (cin >> ch) {
        if (c == ch)
            return;
    }
}

/*******************************************************************************
 ******************************************************************************/
bool Token_stream::full() {
    return (!buffer.empty());
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
        default:
            error("primary expected");
    }
}

/*******************************************************************************
 ******************************************************************************/
int factorial(int n) {
    if (n < 0)
        error("factorial: negative argument");
    int res = 1;
    while (n > 0) {
        res *= n;
        --n;
    }
    return res;
}

/*******************************************************************************
 ******************************************************************************/
double term() {
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
            case '!':
                left = factorial(left);
                t = ts.get();
                break;
            case '*':
                left *= primary();
                t = ts.get();
                break;
            case '/':
            {
                double d = primary();
                if (d == 0) error("division by zero");
                left /= d;
                t = ts.get();
                break;
            }
            case '%':
            {
                double d = primary();
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
        case '-':
            return 0.0 - expression();
        case '+':
            return expression();
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
double assignment(Token& t) {
    // assume variable name is in t
    // assume assign token has been seen
    string var_name = t.name;
    double d = expression();
    set_value(var_name, d);
    return d;
}

/*******************************************************************************
 ******************************************************************************/
double declaration() {
    // assume "let" has been seen
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
    define_name(var_name, d);   // declare new variable called "name" with the initial value "expression"
    return d;
}

/*******************************************************************************
 ******************************************************************************/
double statement() {
    Token t = ts.get();
    switch (t.kind) {
        case let:
            return declaration();
        case name:
        {
            Token t2 = ts.get();
            if (t2.kind == assign)      // name "="
                return assignment(t);
            ts.putback(t2);
            ts.putback(t);
            return expression();        // name ...
        }
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

        // predefine names:
        define_name("pi", 3.1415926535);
        define_name("e", 2.7182818284);

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

