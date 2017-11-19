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
    return 0;
}

int combination(int a, int b) {
    if (a < 0 || b < 0)
	error("negative argument passed to combination.");
    return 0;
}


int main() {
    int a = -1, b = -1;
    cout << "\nEnter two positive numbers: ";
    cin >> a >> b;   
    while (a < 0 || b < 0) {
        cout << "\nPlease try again. Enter two positive numbers: ";
        if (!cin)
            cin.clear();
        cin >> a >> b;
    }

    
    
    return 0;
}