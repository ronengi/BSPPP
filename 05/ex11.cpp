#include "std_lib_facilities.h"

/*
 * Fibonacci series
 */
void fibonacci(vector<int>& fib, int elements) {
    if (elements <= 0)    throw runtime_error("illegal number of elements.");
    // also check if fib is a valid Fibonacci series

    for (int i=fib.size(); i < elements; ++i) {
        if (fib.size() < 2)
            fib.push_back(1);
        else
            fib.push_back(fib[fib.size()-1] + fib[fib.size()-2]);
    }
}

int main() {
    vector<int> fib(0);
    int elements = 46;
    cout << "Enter number of elements: ";
    cin >> elements;
    cout << "\n";
    try {
        fibonacci(fib, elements);
        for (int i: fib)
            cout << "\t" << i << "\n";
    }
    catch (runtime_error& e) {
        cerr << "runtime error: " << e.what() << "\n";
    }
    catch (...) {
        cerr << "some other error occured." << "\n";
    }

    cout << "\n";
    return 0;
}
