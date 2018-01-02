#include <iostream>
#include <fstream>

using namespace std;


int main() {
    ifstream ifs{"ex_02.cpp"};
    if (!ifs)
        throw runtime_error("couldn't open file");
    string word{"line"};
    int line_number = 0;
    for(string line; getline(ifs, line); ) {        // read a line
        ++line_number;
        if (line.find(word) != string::npos)        // search for the word
            cout << line_number << '\t'             // write the line
                << line << '\n';
    }
}
