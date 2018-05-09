/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <map>
#include <iostream>
#include <numeric>
using namespace std;


map<string, double> dow_price = {
    {"MMM", 81.86},
    {"AA", 34.69},
    {"MO", 54.45}
};


map<string, double> dow_weight = {
    {"MMM", 5.8549},
    {"AA", 2.4808},
    {"MO", 3.8940}
};

map<string, string> dow_name = {
    {"MMM", "3M Co."},
    {"AA", "Alcoa Inc."},
    {"MO", "Altria Group Inc."}
};


double weighted_value_func(
    const pair<string, double>& a,
    const pair<string, double>& b
    ) {
    return a.second * b.second;
}

class weighted_value_obj {
public:
    double operator()(const pair<string, double>& a,
        const pair<string, double>& b) {
        return a.second * b.second;
    }

};


int dowjones() {
    for(auto p : dow_price) {
        cout << p.first << '\t'
            << p.second << '\t'
            << dow_name[p.first] << '\n';
    }

    cout << "\n\n";

    double dji_index =
        inner_product(dow_price.begin(), dow_price.end(),   // all prices
        dow_weight.begin(),                                 // their weights
        0.0,                                                // initial value
        plus<double>(),                                     // add
        weighted_value_obj{}        // extract value and weight and multiply
        //weighted_value_func       // extract value and weight and multiply
        );

    double dji_weight = accumulate(dow_weight.begin(), dow_weight.end(),
        0.0,
        [](double acc, const pair<string, double>& pp2) { return acc + pp2.second; }
        );

    cout << "total prices * weights: " << dji_index << '\n';
    cout << "total weights: " << dji_weight << '\n';
    cout << dji_index / dji_weight << '\n';

    return 0;
}
