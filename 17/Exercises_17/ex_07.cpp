/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>

using namespace std;


void print(char* s);


void copyCharArr(const char* s, char* s1) {
    while(*s1++ = *s++) ;
}


void main_07() {
    cout << "Enter characters (! to exit):\n";
    int max = 2;
    int sz = 0;
    char* s = new char[max];
    s[sz] = '\0';

    for(char ch; cin.get(ch) && ch != '!'; ) {
        if(ch == '\n')
            continue;
        if (sz == max) {
            max *= 2;
            char* s1 = new char[max];
            copyCharArr(s, s1);
            delete[] s;
            s = s1;
        }
        s[sz++] = ch;
        s[sz] = '\0';
    }
    print(s);
    delete[] s;

    cout << "Bye\n";
}

