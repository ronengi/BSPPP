#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

int main() {
  ifstream ifs("ex_01.in");
  if (!ifs)    throw runtime_error("failed to open file for reading");
  ifs.exceptions(ifs.exceptions() | ios_base::badbit);

  int i, sum = 0;
  char ch;

  while (!ifs.eof()) {
    ifs >> i;
    if (ifs.fail()) {
      ifs.clear();
      ifs >> ch;
    }
    else if (ifs.good())
      sum += i;
  }

  cout << "Sum of all numbers in file is: " << sum << endl;



  return 0;
}
