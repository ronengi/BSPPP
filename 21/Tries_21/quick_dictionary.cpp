/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;


struct clean_char {
    bool operator()(char ch) {
        return ispunct(ch);
    }
};


struct clean_str {
    void operator()(string& str) {
        str.erase(remove_if(str.begin(), str.end(), clean_char()), str.end());
        transform(str.begin(), str.end(), str.begin(), ::tolower);
//        str[j] = tolower(str[i]);
    }
};

int qdict() {
    ifstream ifs{"src.txt"};    // open input stream
    ofstream ofs{"dst.txt"};    // open output stream

    istream_iterator<string> ii{ifs};           // make input iterator for stream
    istream_iterator<string> eos;               // input sentinel
    ostream_iterator<string> oo{ofs, "\n"};     // make output iterator for stream

    vector<string> b{ii, eos};      // buffer is a vector initialized from input
    for_each(b.begin(), b.end(), clean_str());

    sort(b.begin(), b.end());       // sort the buffer
    // copy(b.begin(), b.end(), oo);   // copy buffer to output
    unique_copy(b.begin(), b.end(), oo);   // copy buffer to output, no duplicates


    return 0;
}