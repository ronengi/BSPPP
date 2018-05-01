/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Text_iterator.hpp"
#include "Document.hpp"


Text_iterator::Text_iterator(list<Line>::iterator ll, Line::iterator pp, const Document* dd) :
    ln{ll}, pos{pp}, docP{dd}
{ }

char& Text_iterator::operator*() {
    return *pos;
}


// increment '++p'
Text_iterator& Text_iterator::operator++() {
    ++pos;                                  // proceed to next character
    if(pos == (*ln).end()) {
        ++ln;                                // proceed to next line
        if(ln != (*docP).doc_lines.end())    // make sure that ln != line.end();
            pos = (*ln).begin();
    }
    return *this;
}

// TODO check if this form is handled correctly
// for 'p++' usage
Text_iterator& Text_iterator::operator++(int i) {
    return operator++();
}


// TODO implement Text_iterator::operator--
Text_iterator& Text_iterator::operator--() {

    return *this;
}

bool Text_iterator::operator==(const Text_iterator& other) {
    return ln == other.ln && pos == other.pos;
}

bool Text_iterator::operator!=(const Text_iterator& other) {
    return !(*this == other);
}
