/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>

using std::cout;
using std::cerr;
using std::out_of_range;


int strcmp(const char *s1, const char* s2, int maxlen) {
    while(*s1 && *s2) {
        if(*s1 > *s2)
            return 1;
        if(*s1 < *s2)
            return -1;
        ++s1;
        ++s2;
        --maxlen;
        if(maxlen < 0)
            throw out_of_range("String exceeded maximum length");
    }
    if(*s1)
        return 1;
    if(*s2)
        return -1;
    return 0;
}


void main_03() {
    const char* s1 = "hello";
    const char* s2 = "hello";

    try {
        cout << strcmp(s1, s2, 3) << "\n";
    }
    catch(out_of_range e) {
        cerr << "out of range error: " << e.what() << "\n";
    }
}
