#include "std_lib_facilities.h"



Token get_token() {
}


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
                ts.putback();
                return left;
        }
    }
}

double term() {
    double left = primary();
    Token t = ts.get();
    while (true) {
        switch (t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/': {
            double d = primary();
            if (d == 0)    error("division by zero");
            lefe /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback();
            return left;
        }
    }
}

double primary() {
    Token t = ts.get();
    switch (t.kind) {
    case '(': {
        double d = expression();
        t = ts.get();
        if (t.kind != ')')    error("')' expected");
        return d;
    }
    case '8':       // represents a number
        retuen t.value;
    default:
        error ("primary expected");
    }
}



int main() {
    try {
        while (cin) {
            Token t = ts.get();
            if (t.kind == 'q')
                break;
            if (t.kind == ';')
                cout << "=" << val << "\n";
            else
                ts.putback(t);
            val = expression();
    }
    catch (exception& e) {
        cerr << e.what() << "/n";
        return 1;
    }
    catch (...) {
        cerr << "exception \n";
        return 2;
    }

    return 0;
}

