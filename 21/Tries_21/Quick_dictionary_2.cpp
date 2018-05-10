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


struct qdict_order {
    bool operator()(const string& a, const string& b) const {
        auto pa = a.begin();
        auto pb = b.begin();
        while(pa != a.end() && pb != b.end()) {
            char ca = tolower(*pa);
            char cb = tolower(*pb);

            if(ispunct(ca) && ispunct(cb)) {
                ++pa;
                ++pb;
                continue;
            }
            if(ispunct(ca)) {
                ++pa;
                continue;
            }
            if(ispunct(cb)) {
                ++pb;
                continue;
            }

            if(ca < cb)
                return true;
            if(ca > cb)
                return false;
            ++pa;
            ++pb;
        }
        while(pb != b.end() && ispunct(*pb))
            ++pb;
        if(pb == b.end())
            return false;
        return true;
    }
};


int qdict2() {
    ifstream ifs{"src.txt"};    // open input stream
    ofstream ofs{"dst2.txt"};    // open output stream

    set<string, qdict_order> b{istream_iterator<string> {ifs}, istream_iterator<string> {}};      // buffer is a set initialized from input

    copy(b.begin(), b.end(), ostream_iterator<string> {ofs, "\n"});   // copy buffer to output, no duplicates


    return 0;
}