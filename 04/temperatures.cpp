#include "std_lib_facilities.h"

int main() {

    vector<double> temps;

    for (double temp; cin >> temp; )
        temps.push_back(temp);

    double sum = 0.0;
    for (double t: temps)
        sum += t;

    cout << "average: " << sum / temps.size() << "\n";

    // compute median
    sort(temps);
    cout << "median: " << temps[temps.size() /2] << "\n";


}
