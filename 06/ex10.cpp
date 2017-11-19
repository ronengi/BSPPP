#include "std_lib_facilities.h"

int factorial(int n) {
    if (n < 0)
        error("negative argument passed to factorial.");
    int res = 1;
    while (n > 0) {
        res *= n;
        --n;
    }
    return res;
}

int permutation(int a, int b) {
    if (a < 0 || b < 0)
        error("negative argument passed to permutation.");
    if (a < b)
        error("first argument smaller than the second.");
    int res = factorial(a) / factorial(a - b);
    return res;
}

int combination(int a, int b) {
    if (a < 0 || b < 0)
        error("negative argument passed to combination.");
    int res = permutation(a, b) / factorial(b);
    return res;
}

int getNatural() {
    int a = 0;
    char ch = ' ';
    string junk = "";
    while (a <= 0 && cin) {
        cin >> ch;
        switch (ch) {
            case '0': case '1': case '2': case '3': case '4': case '5':
            case '6': case '7': case '8': case '9':
                cin.putback(ch);
                cin >> a;
                break;
            case '-': case '.':
                cin >> junk;
                a = 0;
                cout << "Natural number only. Please try again: ";
                break;
            default:
                cin >> junk;
                cout << "Illegal input. Please try again: ";
                a = 0;
                break;
        }
    }
    if (a <= 0)
        error("Failed to get natural number.");
    return a;
}

int getChoice() {
    return 1;
}


int main() {
    int a = 0, b = 0, choice = 0, res = 0;
    cout << "\nEnter two natural numbers: ";
    a = getNatural();
    b = getNatural();
    if (b > a) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    cout << "\nCalculate permutation(1) or combination(2)? ";
    choice = getChoice();
    switch (choice) {
        case 1:
            res = permutation(a, b);
            cout << "\nP(" << a << ", " << b << ")== " << res << "\n";
            break;
        case 2:
            res = combination(a,b);
            cout << "\nC(" << a << ", " << b << ")== " << res << "\n";
            break;
        default:
            error("Illegal choice");
            break;
    }


    return 0;
}