/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>

using std::cout;
using std::cerr;
using std::out_of_range;


int strlen(const char* str, int maxlen) {
    int len = 0;
    while(*str) {
        ++str;
        ++len;
        --maxlen;
        if(maxlen < 0)
            throw out_of_range("String exceeded maximum length");
    }
    return len;
}


char* strdup(const char* str1, int maxlen) {
    int len = strlen(str1, maxlen);
    char* str2 = new char[len+1];
    char* copy = str2;
    while(*str1) {
        *copy = *str1;
        ++copy;
        ++str1;
        --maxlen;
        if(maxlen < 0)
            throw out_of_range("String exceeded maximum length");
    }
    *copy = '\0';
    return str2;
}


/*
 *
 */
void main_01() {

    const char* s = "Hello.";
    try {
        char* copy = strdup(s, 3);
        cout << copy << "\n";
        delete[] copy;
    }
    catch(out_of_range e) {
        cerr << "out of range error: " << e.what() << "\n";
    }


}