#include "std_lib_facilities.h"

/*
 * Calculate median value for vector of doubles.
 */

double median(vector<double> values) {
    int med_low = values.size() / 2;
    if (values.size() % 2 == 1)
        return values[med_low];
    return (values[med_low] + values[med_low - 1]) /2;
}


int main() {
    vector<double> values = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    vector<double> values_1 = {1.0, 2.0, 3.0, 4.0, 5.0};
    cout << "Median is: " << median(values) << "\n\n";
    cout << "Median is: " << median(values_1) << "\n\n";
}
