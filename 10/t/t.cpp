#include <iostream>
#include <vector>
using namespace std;


struct Str {
  vector<int> iii (4, 100);
  int ii;
};


int main() {


  vector<Str> clock;
  Str s1;

  for (int i = 0; i < 12; ++i) {
    s1.ii = i;
    clock.push_back(s1);
  }


  for (int i = 0; i < clock.size(); ++i)
    cout << clock[i].ii << endl;




}
