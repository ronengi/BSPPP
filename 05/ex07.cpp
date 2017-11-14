#include "std_lib_facilities.h"

/*
 * Calculate the roots of a quadratic equasion
 */
void calc_roots(double a, double b, double c, vector<double>& roots) {

    if (roots.size() > 0)
        throw runtime_error("roots vector is not empty.");

    if (a == 0.0)
        throw runtime_error("This is not a quadratic equasion.");

    double d = b * b - 4 * a * c;
    if (d < 0.0)
        throw runtime_error("This equasion has no roots.");

    else if (d == 0.0)
        roots.push_back(-b / (2 * a));

    else {
        roots.push_back((-b + sqrt(d))/ (2 * a));
        roots.push_back((-b - sqrt(d))/ (2 * a));
    }
}



int main() {
    double a = 0.0, b = 0.0, c = 0.0;
    vector<double> roots(0);

    cout << "\nEnter a, b and c: ";
    cin >> a >> b >> c;
    
    try {
        calc_roots(a, b, c, roots);
        for (double r: roots)
            cout << "\t" << r << "\n";
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
