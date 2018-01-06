#include <iostream>
#include <fstream>
using namespace std;


void flip_file(const string& ifname, const string& ofname) {
    ifstream ifs{ifname};
    if (!ifs)
        throw runtime_error("Can't open file " + ifname);
    ofstream ofs{ofname};
    if (!ofs)
        throw runtime_error("Can't open file " + ofname);
    char ch;
    ifs.seekg(0, ifs.end);
    for(int ifpos = ifs.tellg(); ifpos > 0; --ifpos) {
        ifs.seekg(ifpos-1, ifs.beg);
        ifs.get(ch);
        ofs.put(ch);
    }
    ofs.put('\n');
}


int main() {
    flip_file("ex_12.cpp", "ex_12.reversed.out");
}
