#include "std_lib_facilities.h"
#include "Name_pairs2.hpp"

using namespace Name_pairs2;


int main() {
    cout << "np1\n";

    Name_pairs np1{};
    np1.read_names();
    np1.read_ages();
    cout << np1 << "\n";
    // np1.sort();
    cout << np1 << "\n";

    cout << "np2\n";

    Name_pairs np2{};
    np2.read_names();
    np2.read_ages();
    cout << np2 << "\n";

    cout << "np1 == np2 ? " << (np1 == np2) << "\n";
}
