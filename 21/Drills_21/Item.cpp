/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Item.hpp"


Item::Item() :
    name{""}, iid{0}, value{0.0}
{ }

Item::Item(string ss) :
    name{ss}, iid{0}, value{0.0}
{ }

Item::Item(string ss, int ii, double dd) :
    name{ss}, iid{ii}, value{dd}
{ }



istream& operator>>(istream& is, Item& it) {
    return is >> it.name >> it.iid >> it.value;
}

ostream& operator<<(ostream& os, const Item& it) {
    return os << left << setw(10) << it.name << right << setw(10) << it.iid << setw(20) << it.value;
}



sort_by::sort_by() :                     field{"name"},  descending{false} { }
sort_by::sort_by(string ff) :            field{ff},      descending{false} { }
sort_by::sort_by(string ff, bool dd) :   field{ff},      descending{dd}    { }

bool sort_by::operator()(const Item& a, const Item& b) {
    bool pred = false;
    if(field == "name")         pred = a.name < b.name;
    else if(field == "iid")     pred = a.iid < b.iid;
    else if(field == "value")   pred = a.value < b.value;
    else                        return false;
    return descending ? !pred :  pred;
}


find_item_by::find_item_by(string nn) :     name{nn}, iid{0}  { }
find_item_by::find_item_by(int ii) :        name{""}, iid{ii} { }

bool find_item_by::operator() (const Item& ii) {
    if(iid == 0)    return ii.name == name;
    if(name == "")  return ii.iid == iid;
    return false;
}
