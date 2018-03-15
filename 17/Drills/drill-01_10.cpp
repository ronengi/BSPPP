#include <iostream>
#include <vector>
using namespace std;


void print_vector(ostream& os, const vector<int>& v) {
  for (int i = 0; i < v.size(); ++i)
    os << "vector[" << i << "] == " << v[i] << endl;
}



int main() {

  int n = 20;

  vector<int> v(n);

  for (int i = 0; i < n; ++i)
    v[i] = 100 + i;

  print_vector(cout, v);

  return 0;
}
