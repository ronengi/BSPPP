#include "std_lib_facilities.h"
#include "Name_pairs2.hpp"

namespace Name_pairs2 {

                                                // public members

    bool Name_pairs::equals(const Name_pairs& other) const {
        if (names.size() != other.names.size())
            return false;

        map<string, double>::const_iterator p1 = names.begin();
        map<string, double>::const_iterator p2 = other.names.begin();
        while (p1 != names.end() && p2 != other.names.end()) {
            if (p1->first != p2->first || p1->second != p2->second)
                return false;
            ++p1;
            ++p2;
        }

        return true;
    }

    string Name_pairs::print() const {
        stringstream ss{};
        for (const auto& p1: names) {
            ss << p1.first << ": " << p1.second << "\n";
        }
        return ss.str();
    }


    /*
    bool names_cmp(const pair<string, double> &a, const pair<string, double> &b) {
        return a.first < b.first;
    }

    void Name_pairs::sort() {
        std::sort(names.begin(), names.end(), names_cmp);
    }
    */


    void Name_pairs::read_names() {
        string new_name;
        cout << "Enter series of names. End with '@'.\n>> ";
        while (cin >> new_name && new_name != "@") {
            add_name(new_name);
            cout << ">> ";
        }
    }

    void Name_pairs::read_ages() {
        double new_age = 0.0;
        for (const auto& p1: names) {
            cout << "Enter age for " << p1.first << ": ";
            cin >> new_age;
            add_age(new_age, p1.first);
        }
    }

                                                // private members

    void Name_pairs::add_name(string new_name) {
        names[new_name] = 0.0;
    }

    void Name_pairs::add_age(double new_age, string index) {
        names[index] = new_age;
    }


                                                // helper functions

    ostream& operator<<(ostream& os, const Name_pairs& np) {
        return os << np.print();
    }

    bool operator==(const Name_pairs& a, const Name_pairs& b) {
        return a.equals(b);
    }

    bool operator!=(const Name_pairs& a, const Name_pairs& b) {
        return !(a == b);
    }

}
