/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

using namespace std;


void main_09() {

    int a = 1;
    int b = 2;

    int* pa = &a;
    int *pb = &b;

    cout << "pa== " << pa << "\n";
    cout << "pb== " << pb << "\n";

    cout << "\n";

    int* pc = new int[40];
    int* pd = new int;

    cout << "pc== " << pc << "\n";
    cout << "pd== " << pd << "\n";

    cout << "\n";

    delete[] pc;
    delete pd;
}
