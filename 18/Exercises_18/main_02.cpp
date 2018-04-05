/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>

using std::cout;
using std::cerr;
using std::out_of_range;


bool findx_2(const char *s, const char* x, int maxlen) {
    while(*s && *x && *s == *x) {
        ++s;
        ++x;
        --maxlen;
        if(maxlen < 0)
            throw out_of_range("String exceeded maximum length");
    }
    if(*x)
        return false;
    return true;
}

char* findx(const char* s, const char* x, int maxlen) {
    int maxlen_1 = maxlen;
    while(*s) {
        if(*s == *x && findx_2(s,x, maxlen))
            return const_cast<char*>(s);
        ++s;
        --maxlen_1;
        if(maxlen_1 < 0)
            throw out_of_range("String exceeded maximum length");
    }
    return nullptr;
}


void main_02() {
    const char* s = "hello world!!";
    const char* x = "rld";
    try{
        char* fx = findx(s, x, 3);
        if(fx)
            cout << fx << "\n";
        else
            cout << "Not found" << "\n";
    }
    catch(out_of_range e) {
        cerr << "out of range error: " << e.what() << "\n";
    }
}