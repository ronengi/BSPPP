#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int main() {
    ifstream ifs{"ex_03.cpp"};
    ofstream ofs{"ex_03.out"};
    if (!ifs || !ofs)
        throw runtime_error("couldn't open file");
    for(string line; getline(ifs, line); ) {        // read a line
        ostringstream oss{};
        for(char c : line) {                        // remove vowels
            switch (c) {
            case 'a': case 'e': case 'i': case 'o': case 'u':
                break;
            default:
                oss << c;
                break;
            }
        }
        ofs << oss.str() << '\n';                  // write the line
    }
}
