#include <iostream>
using namespace std;


void print_array_n(ostream& os, int* a, int n) {
  for (int i = 0; i < n; ++i)
    os << "array[" << i << "] == " << a[i] << endl;
}



int main() {

  int i1 = 7, *p1 = &i1;
  cout << "p1 == " << p1 << endl;
  print_array_n(cout, p1, 1);
  cout << endl;

  int *p2 = new int[7];
  for (int i = 0, pow = 1; i < 7; ++i, pow *= 2)
    p2[i] = pow;
  cout << "p2 == " << p2 << endl;
  print_array_n(cout, p2, 7);
  cout << endl;

  int *p3 = p2;
  p2 = p1;
  p2 = p3;

  cout << "p1 == " << p1 << endl;
  cout << "p2 == " << p2 << endl;
  cout << endl;

  delete[] p2;


  p1 = new int[10];
  for (int i = 0, pow = 1; i < 10; ++i, pow *= 2)
    p1[i] = pow;
  cout << "p1 == " << p1 << endl;
  print_array_n(cout, p1, 10);
  cout << endl;


  p2 = new int[10];
  for (int i = 0; i < 10; ++i)
    p2[i] = p1[i];
  cout << "p2 == " << p2 << endl;
  print_array_n(cout, p2, 10);
  cout << endl;

  delete[] p1;
  delete[] p2;



  return 0;

  // int n = 20;
  // int *pi = new int[n];
  // for (int i = 0; i < n; ++i)
  //   pi[i] = 100 + i;
  // print_array_n(cout, pi, n);
  // delete[] pi;
}
