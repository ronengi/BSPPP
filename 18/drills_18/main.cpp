/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Ronen Gilead-Raz <ronengi@gmail.com>
 *
 * Created on April 3, 2018, 6:14 PM
 */

#include <iostream>
#include <vector>

using namespace std;


int ga[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};


void f1(int arr[], int n) {
    int la[10];
    for(int i =0; i < n; ++i) {
        la[i] = arr[i];
        cout << la[i] << " ";
    }
    cout << "\n";

    int* p = new int[n];
    for(int i =0; i < n; ++i) {
        *(p+i) = arr[i];
        cout << *(p+i) << " ";
    }
    cout << "\n";

    delete[] p;
}


void f2(vector<int> vi) {
    vector<int> lv{vi};
    for(int i : lv)
        cout << i << " ";
    cout << "\n";
    vector<int> lv2(vi);
    for(int i : lv2)
        cout << i << " ";
    cout << "\n";
}


/*
 *
 */
int main(int argc, char** argv) {

    f1(ga, 10);
    cout << "\n";

    int aa[10];
    aa[0] = 1;
    for(int i = 1; i < 10; ++i)
        aa[i] = aa[i-1] * (i+1);
    f1(aa, 10);


    cout <<"\n\n";

    f2(gv);
    cout << "\n";

    vector<int> vv;
    vv.push_back(1);
    for(int i = 1; i < 10; ++i)
        vv.push_back(vv[i-1] * (i+1));
    f2(vv);

    cout <<"\n\n";

    return 0;
}

