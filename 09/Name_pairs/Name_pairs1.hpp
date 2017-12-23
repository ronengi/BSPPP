#include "std_lib_facilities.h"

#ifndef NAME_PAIRS1_H
#define NAME_PAIRS1_H

namespace Name_pairs1 {

    class Name_pairs {
    public:
        bool equals(const Name_pairs& other) const;
        string print() const;
        void sort();
        void read_names();
        void read_ages();

    private:
        vector<string> name;
        vector<double> age;

        void add_name(string new_name);
        void add_age(double new_age, int index);
        void swap(int i, int j);

    };

    ostream& operator<<(ostream& os, const Name_pairs& np);
    bool operator==(const Name_pairs& a, const Name_pairs& b);
    bool operator!=(const Name_pairs& a, const Name_pairs& b);

}

#endif // NAME_PAIRS1_H
