// concatenate two files

#include <iostream>
#include <fstream>
using namespace std;


int main() {
  ifstream src1("srcfile1");
  ifstream src2("srcfile2");
  ofstream dst("dstfile");
  string word1, word2;

  // first read
  src1 >> word1;
  src2 >> word2;

  // as long as both files aren't finished
  while (src1  &&  src2) {
    if (word1 < word2) {
      dst << word1 << " ";
      src1 >> word1;
    }
    else {
      dst << word2 << " ";
      src2 >> word2;
    }
  }

  // file 1 isn't finished
  // there is still an unused word in word1
  while (src1) {
    dst << word1 << " ";
    src1 >> word1;
  }

  // file 2 isn't finished
  // there is still an unused word in word2
  while (src2) {
    dst << word2 << " ";
    src2 >> word2;
  }


  return 0;
}
