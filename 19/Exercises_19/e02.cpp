/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <stdexcept>
using namespace std;

template<typename T, typename U>
T f02(vector<T>& vt, vector<U>& vu) {
    T sum{};
    int sz = vt.size();
    if(sz != vu.size())
        throw runtime_error("vectors have different sizes");
    for(int i = 0; i < sz; ++i)
        sum += vt[i] * vu[i];
    return sum;
}