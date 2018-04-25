/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
using namespace std;


template<typename T>
void f01(vector<T>& v1, vector<T>& v2) {
    int sz1 = v1.size();
    int sz2 = v2.size();
    sz1 = (sz1 > sz2) ? sz2 : sz1;
    for(int i = 0; i < sz1; ++i)
        v1[i] += v2[i];
}