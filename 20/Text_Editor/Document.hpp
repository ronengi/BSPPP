/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/*
 * File:   Document.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on April 30, 2018, 9:15 AM
 */

#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

using Line = vector<char>;
class Text_iterator;

/*
* Text document: collection of lines, each of which is a collection of chars.
*/
struct Document {
    list<Line> doc_lines;
    Document();                     // add empty line on creation

    Text_iterator begin();          // first character of first line
    Text_iterator end();            // one beyond the last character of the last line

    void erase_line(int n);         // delete line number n (if exists)

    bool match(Text_iterator first, Text_iterator last, const string& s);
    Text_iterator find_txt(Text_iterator first, Text_iterator last, const string& s);

};


istream& operator>>(istream& is, Document& d);

#endif // DOCUMENT_HPP

