#include <iostream>
using namespace std;


void print_array_n(ostream& os, int* a, int n) {
  for (int i = 0; i < n; ++i)
    os << "array[" << i << "] == " << a[i] << endl;
}



int main() {

  int n = 20;

  int *pi = new int[n];

  for (int i = 0; i < n; ++i)
    pi[i] = 100 + i;


  print_array_n(cout, pi, n);



  delete[] pi;

  return 0;
}
