#include "std_lib_facilities.h"
#include <cfloat>

constexpr double cm = 1 / 100.0;
constexpr double in = 2.54 * cm;
constexpr double ft = 12 * in;



void prompt() {
    cout << "Enter double and a unit: ";
}


double convert_to_meters(double d, string unit) {
    if (unit == "m")        {}
    else if (unit == "cm")  { d *= cm; }
    else if (unit == "in")  { d *= in; }
    else if (unit == "ft")  { d *= ft; }
    else                    { d = 0.0;    cout << "I don't know such a unit: " << unit << "\n"; }
    return d;
}


int main() {

    double smallest = DBL_MAX, smallest_meters = DBL_MAX,
            largest = DBL_MIN, largest_meters = DBL_MIN,
            num = 0.0, num_meters = 0.0,
            sum = 0.0;
    int values = 0;
    string unit = "" , smallest_unit = "", largest_unit = "";
    vector<double> lengths(0);

    prompt();
    for ( ; cin >> num >> unit ; ) {
        num_meters = convert_to_meters(num, unit);
        lengths.push_back(num_meters);
        cout << "\tValue entered: " << num << unit << "\n";
        // cout << "value in meters: " << num_meters << "\n";
        if (smallest_meters > num_meters) {
            smallest = num;
            smallest_unit = unit;
            smallest_meters = num_meters;
            cout << "\tSmallest so far\n";
        }
        if (largest_meters < num_meters) {
            largest = num;
            largest_unit = unit;
            largest_meters = num_meters;
            cout << "\tLargest so far\n";
        }
        prompt();

        ++values;
        sum += num_meters;

    }

    cout << "Smallest: " << smallest << smallest_unit << "\n";
    cout << "Largest: " << largest << largest_unit << "\n";
    cout << "Number of values entered: " << values << "\n";
    cout << "Sum of values in meters: " << sum << "m" << "\n";

    cout << "\n\n";
    sort(lengths);

    for (double x: lengths)
        cout << x << "m\n";

    cout << "\n\n";

}

