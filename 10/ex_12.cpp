#include <iostream>
#include <fstream>
using namespace std;


void grep(string fname, string word) {
  ifstream ifs(fname.c_str());
  char cline[256];
  string line;
  int num = 0;

  while (ifs.getline(cline, 256, '\n')) {
    ++num;
    line = cline;
    if (line.find(word) != string::npos)
      cout << num << ":\t" << line << endl;
  }


}

int main() {
  grep ("srcfile", "ele");

  return 0;
}
