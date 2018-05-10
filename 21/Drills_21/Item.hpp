/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Item.hpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on May 11, 2018, 12:52 AM
 */

#ifndef ITEM_HPP
#define ITEM_HPP

#include <iomanip>
#include <vector>
using namespace std;

struct Item {
    Item();
    Item(string ss);
    Item(string ss, int ii, double dd);

    string name;
    int iid;
    double value;
};


istream& operator>>(istream& is, Item& it);
ostream& operator<<(ostream& os, const Item& it);

template<template<typename> typename C>
ostream& operator<<(ostream& os, const C<Item>& cit) {
    constexpr int seplength = 100;
    os << "\n";
    for(int i = 0; i < seplength; ++i) os << "-";
    os << "\n";
    for(auto p : cit)
        os << "\t" << p << "\n";
    for(int i = 0; i < seplength; ++i) os << "-";
    return os << "\n";
}

struct sort_by {
    sort_by();
    sort_by(string ff);
    sort_by(string ff, bool dd);

    bool operator()(const Item& a, const Item& b);

    string field;
    bool descending;
};


struct find_item_by {
    find_item_by(string nn);
    find_item_by(int ii);

    bool operator() (const Item& ii);

    string name;
    int iid;
};



#endif /* ITEM_HPP */
