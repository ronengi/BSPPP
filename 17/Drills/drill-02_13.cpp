#include <iostream>
#include <vector>
using namespace std;


void print_vector(ostream& os, const vector<int> &v) {
  for (int i = 0; i < v.size(); ++i)
    os << "vector[" << i << "] == " << v[i] << endl;
}


int main() {

  vector<int> v(10);
  for (int i = 0, pow = 1; i < v.size(); ++i, pow *= 2)
    v[i] = pow;
  cout << "v == " << &v << endl;
  print_vector(cout, v);
  cout << endl;


  return 0;
}
