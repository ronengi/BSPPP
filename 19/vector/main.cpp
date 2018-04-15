/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on March 14, 2018, 12:06 AM
 */

#include <iostream>
#include <stdexcept>
#include "vector.hpp"

using std::cout;
using std::cerr;
using std::string;

using std::out_of_range;
using std::runtime_error;
using std::exception;


/*
 *
 */
int main(int argc, char** argv) {
    int n = 5;

    simplified::vector<double> v1(n);
    for(int i = 0; i < n; ++i) {
        v1[i] = 1.1 * i;
    }
    cout << v1 << "\n";

    try {
        cout << v1.at(-1) << "\n";
    }
    catch(out_of_range& e) {
        cerr << "\nOut Of Range Error: " << e.what() << "\n\n";
    }

    simplified::vector<string> v2{"hello", "how", "are", "you", " ? "};
    cout << v2 << "\n";

    simplified::vector<string> v3{v2};      // v3 = v2
    cout << v3 << "\n";

    v2[1] = "who";
    v3[0] = "and";
    cout << v2 << "\n";
    cout << v3 << "\n";

    simplified::vector<string> v4(2);
    cout << v4 << "\n";

    v4 = v3;
    cout << v4 << "\n";


    return 0;
}

