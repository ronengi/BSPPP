/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on March 15, 2018, 11:36 PM
 */

#include <iostream>

using namespace std;

void main_03();
void main_04();
void main_05();

/*
 *
 */
void print(char* s) {
    cout << "\n";
    for(int i = 0; s[i] != '\0'; ++i)
        cout << s[i];
    cout << "\n";
}


/*
 *
 */
int main(int argc, char** argv) {

    // main_03();
    // main_04();
    main_05();

    return 0;
}

