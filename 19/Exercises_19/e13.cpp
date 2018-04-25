/*
 * Tracer class
 *
 */

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

// TODO: implement copy constructor, copy assignment
class Tracer {
public:
    Tracer() {
        ++index;
        id = index;
        cerr << get_id() << "constructor" << "\n";
    }

    ~Tracer() {
        cerr << get_id() << "destructor" << "\n";
    }


private:
    string get_id() {
        ostringstream os;
        os << "{Tracer " << setw(2) << id << "}: ";
        return os.str();
    }

    static int index;
    int id;
};