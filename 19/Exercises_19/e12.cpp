/*
 * File_handle
 *
 */

#include <iostream>
#include <fstream>
using namespace std;


class File_handle {

public:
    File_handle() =delete;
    File_handle(string fn) :
        file_name{fn}
    {
        ifs = new ifstream{file_name, ios_base::in};
    }

    ~File_handle() {
        ifs->close();
        delete ifs;
    }


    void print_all() {
        ifs->seekg(0);
        char ch = ifs->get();
        while (*ifs) {
            cout << ch;
            ch = ifs->get();
        }
    }

private:
    ifstream* ifs;
    string file_name;
};