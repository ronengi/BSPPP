#include <iostream>
#include <vector>
#include <list>
using namespace std;

#include "Iterator.hpp"
#include "Vector_iterator.hpp"
#include "List_iterator.hpp"



void print(Iterator& it) {
  double *pd;
  while (true) {
    pd = it.next();
    if (pd != 0)
      cout << *pd << endl;
    else
      break;
  }
}


int main() {

  vector<double> vd;
  vd.push_back(1.2);
  vd.push_back(3.4);

  list<double> ld;
  ld.push_back(5.6);
  ld.push_back(7.8);

  Vector_iterator vi(vd);
  List_iterator li(ld);


  print(vi);
  cout << endl;
  print(li);


  return 0;
}
