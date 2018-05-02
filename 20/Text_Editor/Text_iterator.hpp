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
 *
 * Satisfies Iterator concept:
 *
 *  all these evaluate as true:
 *      is_copy_constructible<Text_iterator>::value
 *      is_copy_assignable<Text_iterator>::value
 *      is_destructible<Text_iterator>::value
 *      is_swappable<Text_iterator>::value
 *
 *  all these are defined:
 *      Text_iterator::difference_type
 *      Text_iterator::value_type
 *      Text_iterator::pointer
 *      Text_iterator::reference
 *      Text_iterator::iterator_category
 *
 */
class Text_iterator {
    list<Line>::iterator ln;
    Line::iterator pos;

    const Document* docP;

public:
    using difference_type = std::ptrdiff_t;
    using value_type = char;
    using pointer = const char*;    //std::allocator_traits<Allocator>::pointer;
    using reference = const char&;  // value_type&;
    using iterator_category = std::forward_iterator_tag;

    Text_iterator(list<Line>::iterator ll, Line::iterator pp, const Document* dd);  // start at line pp, char pos

    char& operator*();

    Text_iterator& operator++();                // increment '++p'
    Text_iterator& operator--();

    Text_iterator& operator++(int i);           // for 'p++' usage

    bool operator==(const Text_iterator& other);
    bool operator!=(const Text_iterator& other);

};


#endif // TEXT_ITERATOR_HPP
