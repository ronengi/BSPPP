#include <iostream>
#include <sstream>
using namespace std;


#ifndef PUNCT_STREAM_H
#define PUNCT_STREAM_H

class Punct_stream {
public:
    Punct_stream(istream& is)
        : source{is}, sensitive{true}
    {}

    void whitespace(const string& s) { white = s; }     // make s the whitespace set
    void add_white(char c) { white += c; }              // add to the whitespace set
    bool is_whitespace(char c);                         // is c in the whitespace set ?
    void case_sensitive(bool b) { sensitive = b; }
    bool is_case_sensitive() { return sensitive; }

    Punct_stream& operator>>(string& s);
    operator bool();

private:
    istream& source;                    // character source
    istringstream buffer;               // we let buffer do our formatting
    string white;                       // characters considered "white"
    bool sensitive;                     // is the stream case sensitive ?

};

#endif	// PUNCT_STREAM_H
