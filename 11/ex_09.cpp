#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

template<class T>
char* as_bytes(T& i) {                  // treat a T as a sequence of bytes
    void* addr = &i;                    // get the address of the first byte of memory used to store the object
    return static_cast<char*> (addr);   // treat that memory as bytes
}

void text_to_binary(string iname, string oname) {
    ifstream ifs{iname};
    if(!ifs)
        throw runtime_error("Can't open input file: " + iname);
    ofstream ofs{oname, ios_base::binary};
    if(!ofs)
        throw runtime_error("Can't open output file: " + oname);
    vector<int> v;
    for(char ch; ifs.get(ch);) // read loop
        v.push_back(static_cast<int> (ch));
    for(int x : v) // write loop
        ofs.write(as_bytes(x), sizeof(int));
}

void binary_to_text(string iname, string oname) {
    ifstream ifs{iname, ios_base::binary};
    if(!ifs)
        throw runtime_error("Can't open input file: " + iname);
    ofstream ofs{oname};
    if(!ofs)
        throw runtime_error("Can't open output file: " + oname);
    vector<char> v;
    for(int x; ifs.read(as_bytes(x), sizeof (int));) // read loop
        v.push_back(static_cast<char> (x));
    for(char ch : v) // write loop
        ofs.put(ch);
}

int main() {
    text_to_binary("ex_09.cpp", "ex_09.bin.out");
    binary_to_text("ex_09.bin.out", "ex_09.text.out");
}
