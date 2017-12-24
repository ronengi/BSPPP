#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream ifs("srcfile");
  char ch = ' ';
  int n = 0, sum = 0;

  while (ifs >> ch) {
    if (isdigit(ch)) {
      ifs.unget();
      ifs >> n;
      sum += n;
    }
  }

  cout << "the sum of all inetegers is: " << sum << endl;


  return 0;
}
