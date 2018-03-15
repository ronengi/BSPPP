#include <iostream>
using namespace std;

void print_c_str(const char *s) {
  while (*s != '\0')
    cout << *s++ << ' ';
  cout << endl;
}

int strlen(const char *s) {
  int l = 0;
  while (*s++)
    ++l;
  return l;
}

char *strdup(const char *s) {
  char *c = new char[strlen(s) + 1], *c1 = c;

  while (*c++ = *s++)
    ;

  return c1;
}


int main() {
  char *s = new char[20];
  s[0] = 'H';
  s[1] = 'e';
  s[2] = 'l';
  s[3] = 'L';
  s[4] = 'o';
  s[5] = ' ';
  s[6] = 'W';
  s[7] = 'o';
  s[8] = '\0';


  print_c_str(s);

  //cout << strlen(s) << endl;

  char *c = strdup(s);
  print_c_str(c);


  delete[] c;
  delete[] s;

  return 0;
}
