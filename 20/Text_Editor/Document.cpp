/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Document.hpp"
#include "Text_iterator.hpp"

istream& operator>>(istream& is, Document& d) {
    for(char ch; is.get(ch); ) {
        // cerr << "ch== " << ch << "\n";
        d.doc_lines.back().push_back(ch);        // add chars to last line
        if(ch == '\n')
            d.doc_lines.push_back(Line{});       // add last empty line after newline
    }
    if(d.doc_lines.back().size())
        d.doc_lines.push_back(Line{});           // add final empty line
    return is;
}


// add empty line on creation
Document::Document() {
    doc_lines.push_back(Line{});
}


// first character of first line
Text_iterator Document::begin() {
    return Text_iterator(doc_lines.begin(), (*doc_lines.begin()).begin(), this);
}


// one beyond the last character of the last line
Text_iterator Document::end() {
    auto last = doc_lines.end();     // one beyond last line
    --last;                     // back to last line: we know the document is not empty
    return Text_iterator(last, (*last).end(), this);
}

// delete line number n (if exists)
void Document::erase_line(int n) {
    if(n < 0 || n >= doc_lines.size())
        return;
    auto p = doc_lines.begin();
    advance(p, n);
    doc_lines.erase(p);
}


// TODO use <algorithms> find: make Text_iterator satisfy iterator concepts
Text_iterator Document::find(Text_iterator first, Text_iterator last, const char& value) {
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return last;
}


bool Document::match(Text_iterator first, Text_iterator last, const string& s) {
    Text_iterator p = first;
    for(auto ps : s) {
        if(p == last)
            return false;
        if(*p != ps)
            return false;
        ++p;
    }
    return true;
}

Text_iterator Document::find_txt(Text_iterator first, Text_iterator last, const string& s) {
    if(s.size() == 0)
        return last;
    char first_char = s[0];
    while(true) {
        auto p = find(first, last, first_char);
        if(p == last || match(p, last, s))
            return p;

            first = ++p;            // look at the next character
    }

}