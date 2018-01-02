#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ifstream ifs{"ex_01.cpp"};
    ofstream ofs{"ex_01.out"};
    if (!ifs || !ofs)
        throw runtime_error("couldn't open file");
    for(string line; getline(ifs, line); ) {        // read a line
        for(char& c : line)                         // convert to uppercase
            c = toupper(c);
        ofs << line << '\n';                               // write the line
    }
}
