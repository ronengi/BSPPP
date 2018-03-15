#include <iostream>
using namespace std;

void print_c_str(const char *s) {
  while (*s != '\0')
    cout << *s++ << ' ';
  cout << endl;
}

void to_lower(char *s) {
  while (*s != '\0') {
    if ('A' <= *s  &&  *s <= 'Z')
      *s -= 'A' - 'a';
    s++;
  }
}


int main() {
  char *s = new char[20];
  s[0] = 'H';
  s[1] = 'e';
  s[2] = 'l';
  s[3] = 'L';
  s[4] = 'o';
  s[5] = '!';
  s[6] = '\0';


  print_c_str(s);
  to_lower(s);
  print_c_str(s);


  delete[] s;

  return 0;
}
