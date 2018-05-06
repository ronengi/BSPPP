/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include "Record.hpp"
using namespace std;



struct total_price {
    double operator()(double val, const Record& rec) {
        return val + rec.unit_price * rec.units;
    }
};


struct unit_price {
    double operator()(double val, const Record& rec) {
        return val + rec.unit_price;
    }
};


struct total_units {
    unsigned int operator()(unsigned int val, const Record& rec) {
        return val + rec.units;
    }
};


/*
 *
 */
int prices() {

    int n = 2;
    vector<Record> recs;
    for(int i = 0; i < n; ++i) {
        Record newrec;
        newrec.unit_price = 2.0;
        newrec.units = 1;
        // recs[i].unit_price = i+1;
        // recs[i].units = 10-i;
        recs.push_back(newrec);
    }

    double total = 0.0;
    total = accumulate(recs.begin(), recs.end(), total, total_price());
    cout << "total price: " << total << "\n";


    unsigned int total1 = 0;
    total1 = accumulate(recs.begin(), recs.end(), total1, total_units());
    cout << "total units: " << total1 << "\n";


    total = 0.0;
    total = accumulate(recs.begin(), recs.end(), total, unit_price());
    cout << "total units price: " << total << "\n";


    return 0;
}

