/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <stdexcept>
using namespace std;


template<typename K, typename V>
struct Pair {
    Pair() =delete;

    Pair(K kk, V vv) :
        key{kk}, value{vv}
    { }


    K key;
    V value;
};


template<typename K, typename V>
struct Sym_table {
    vector<Pair<K, V>> pairs;

    V get(K kk) {
        for(int i = 0; i < pairs.size(); ++i) {
            if(pairs[i].key == kk)
                return pairs[i].value;
        }
        throw out_of_range("no such key");
    }

    void set(K kk, V vv) {
        for(int i = 0; i < pairs.size(); ++i) {
            if(pairs[i].key == kk) {
                pairs[i].value = vv;
                return;
            }
        }
        Pair np{kk, vv};
        pairs.push_back(np);
    }

};
