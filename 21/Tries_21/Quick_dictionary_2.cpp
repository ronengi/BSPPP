/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <fstream>
#include <iterator>
#include <set>
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

int qdict2() {
    ifstream ifs{"src.txt"};    // open input stream
    ofstream ofs{"dst2.txt"};    // open output stream

               // make input iterator for stream
        // make output iterator for stream

    set<string> b{istream_iterator<string> {ifs}, istream_iterator<string> {}};      // buffer is a vector initialized from input
//    for_each(b.begin(), b.end(), clean_str());

    copy(b.begin(), b.end(), ostream_iterator<string> {ofs, "\n"});   // copy buffer to output, no duplicates


    return 0;
}