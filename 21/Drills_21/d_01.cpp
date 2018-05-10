/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "Item.hpp"
using namespace std;


int d_01() {
    ifstream ifs{"d_01_src.txt"};
    vector<Item> items{istream_iterator<Item> {ifs}, istream_iterator<Item> {}};
    cout << items << "\n";

//    sort(items.begin(), items.end(), sort_by("name"));
//    sort(items.begin(), items.end(), sort_by("iid", true));
//    sort(items.begin(), items.end(), sort_by("value"));
//    sort(items.begin(), items.end(), sort_by("value", true));
//    cout << items << "\n";

//    items.insert(
//        items.begin(),
//        {Item{"horse shoe", 99, 12.34}, Item{"Canon S400", 9988, 499.95}}
//    );
//    cout << items << "\n";

    // predicate is a lambda
//    auto p = find_if(items.begin(), items.end(), [](Item it) {return it.name == "And";});
//    auto p = find_if(items.begin(), items.end(), [](Item it) {return it.iid == 12;});

    //predicate is a function object
//    auto p = find_if(items.begin(), items.end(), find_item_by("And"));
    auto p = find_if(items.begin(), items.end(), find_item_by(12));

    if(p != items.end())
        items.erase(p);
    cout << items << "\n";

    return 0;
}
