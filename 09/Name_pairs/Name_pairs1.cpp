#include "std_lib_facilities.h"
#include "Name_pairs1.hpp"

namespace Name_pairs1 {


                                                // public members

    bool Name_pairs::equals(const Name_pairs& other) const {
        if (name.size() != other.name.size())
            return false;
        for (int i = 0; i < name.size(); ++i) {
            if (name[i] != other.name[i])
                return false;
            if (age[i] != other.age[i])
                return false;
        }
        return true;
    }

    string Name_pairs::print() const {
        stringstream ss{};
        for (int i = 0; i < name.size(); ++i) {
            ss << name[i] << ": " << age[i] << "\n";
        }
        return ss.str();
    }

    void Name_pairs::sort() {
        // implementation of selection sort
        for (int i = 0; i < name.size()-1; ++i) {
            for (int j = i+1; j < name.size(); ++j) {
                if (name[j] < name[i])
                    swap(i, j);
            }
        }
    }

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
        for (int i = 0; i < name.size(); ++i) {
            cout << "Enter age for " << name[i] << ": ";
            cin >> new_age;
            add_age(new_age, i);
        }
    }

                                                // private members

    void Name_pairs::add_name(string new_name) {
        name.push_back(new_name);
        age.push_back(0.0);
    }

    void Name_pairs::add_age(double new_age, int index) {
        age[index] = new_age;
    }

    void Name_pairs::swap(int i, int j) {
        string temp_name = name[i];
        double temp_age = age[i];

        name[i] = name[j];
        age[i] = age[j];

        name[j] = temp_name;
        age[j] = temp_age;
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
