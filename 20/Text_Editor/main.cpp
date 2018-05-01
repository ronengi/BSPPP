/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/*
 * 20.6 An example: a simple text editor
 *   Represents the characters of a text document in a simple text editor.
 *   The representation should make operations on the document simple and
 *   reasonably efficient.
 *
 *
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on April 30, 2018, 9:14 AM
 */

#include "Document.hpp"
#include "Text_iterator.hpp"


using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    Document d1{};
    cin >> d1;

    d1.erase_line(1);


    cout << "\n";
    for(auto p : d1)
        cout << p;
    cout << "\n";

    if(d1.find_txt(d1.begin(), d1.end(), "bye") == d1.end())
        cout << "not found";
    else
        cout << "found";
    cout << "\n";


    return 0;
}

