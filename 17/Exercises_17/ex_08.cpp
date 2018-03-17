/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>

using namespace std;


void main_08() {
    cout << "Enter characters (! to exit):\n";
    string s = "";

    for(char ch; cin.get(ch) && ch != '!'; ) {
        if(ch == '\n')
            continue;
        s += ch;
    }
    cout << s << '\n';

    cout << "Bye\n";
}

