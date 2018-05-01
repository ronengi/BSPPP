/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/*
 * File:   Text_iterator.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on April 30, 2018, 9:39 AM
 */

#ifndef TEXT_ITERATOR_HPP
#define TEXT_ITERATOR_HPP


#include <iostream>
#include <list>
#include <vector>

#include "Document.hpp"
using namespace std;

using Line = vector<char>;
class Document;


/*
 * Keep track of line and character position within a line
 */
class Text_iterator {
    list<Line>::iterator ln;
    Line::iterator pos;

    const Document* docP;

public:
    Text_iterator(list<Line>::iterator ll, Line::iterator pp, const Document* dd);  // start at line pp, char pos

    char& operator*();

    Text_iterator& operator++();
    Text_iterator& operator--();

    bool operator==(const Text_iterator& other);
    bool operator!=(const Text_iterator& other);

};


#endif // TEXT_ITERATOR_HPP
