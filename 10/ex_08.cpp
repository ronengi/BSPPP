// concatenate two files

#include <iostream>
#include <fstream>
using namespace std;


int main() {
  ifstream src1("srcfile1");
  ifstream src2("srcfile2");
  ofstream dst("dstfile");

  char ch;

  while (src1.get(ch))
    dst.put(ch);

  while (src2.get(ch))
    dst.put(ch);

  return 0;
}
