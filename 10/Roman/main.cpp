#include <iostream>
#include <stdexcept>
//#include <cctype>
using namespace std;

#define MAX_ROMAN 3999

string thousands(int n) {
  switch (n) {
  case 1:
    return "M";
  case 2:
    return "MM";
  case 3:
    return "MMM";
  }
  return "";
}
string hundreds(int n) {
  switch (n) {
  case 1:
    return "C";
  case 2:
    return "CC";
  case 3:
    return "CCC";
  case 4:
    return "CD";
  case 5:
    return "D";
  case 6:
    return "DC";
  case 7:
    return "DCC";
  case 8:
    return "DCCC";
  case 9:
    return "CM";
  }
  return "";
}
string tens(int n) {
  switch (n) {
  case 1:
    return "X";
  case 2:
    return "XX";
  case 3:
    return "XXX";
  case 4:
    return "XL";
  case 5:
    return "L";
  case 6:
    return "LX";
  case 7:
    return "LXX";
  case 8:
    return "LXXX";
  case 9:
    return "XC";
  }
  return "";
}
string ones(int n) {
  switch (n) {
  case 1:
    return "I";
  case 2:
    return "II";
  case 3:
    return "III";
  case 4:
    return "IV";
  case 5:
    return "V";
  case 6:
    return "VI";
  case 7:
    return "VII";
  case 8:
    return "VIII";
  case 9:
    return "IX";
  }
  return "";
}
string int_to_roman(int n) {
  if (n < 1  ||  MAX_ROMAN < n)
    throw runtime_error("illegl number");

  int i4 = (n / 1000) % 10;
  int i3 = (n / 100) % 10;
  int i2 = (n / 10) % 10;
  int i1 = (n) % 10;

  string rom = "";
  rom += thousands(i4);
  rom += hundreds(i3);
  rom += tens(i2);
  rom += ones(i1);
  return rom;
}

int get_roman_digit(char rd) {
  rd = tolower(rd);
  switch(rd) {
  case 'i':
    return 1;
  case 'v':
    return 5;
  case 'x':
    return 10;
  case 'l':
    return 50;
  case 'c':
    return 100;
  case 'd':
    return 500;
  case 'm':
    return 1000;
  }
  throw runtime_error("illegal roman symbol");
  return 0;
}
int roman_to_int(string r) {
  int biggest = 0;
  int n = 0;
  int rd = 0;
  bool substracted_once = false;
  for (int i = r.length() - 1; i >= 0; --i) {
    rd = get_roman_digit(r[i]);
    if (rd >= biggest) {
      n += rd;
      biggest = rd;
      substracted_once = false;
    }
    else {
      if (substracted_once)
	throw runtime_error("illegal roman number");
      n -= rd;
      substracted_once = true;
    }
  }

  if (n < 1  ||  MAX_ROMAN < n)
    throw runtime_error("illegal roman number");
  return n;
}

int main() {
  string r = "i";
  int i = 1;

  for (int n = 1; n < 4000; ++n) {
    r = int_to_roman(n);
    i = roman_to_int(r);
    cout << n << ":\t" << r << "\t\t" << i << endl;
  }

  cout << endl;
  return 0;
}





/*
  int n = 0, pn = 0;
  char ch = ' ';
  while(cin >> ch) {
    ch = tolower(ch);
    if (ch != 'i'  &&  ch != 'v'  &&  ch != 'x'  &&  ch != 'l'  &&  ch != 'c'  &&  ch != 'd'  &&  ch != 'm') {
      cin.unget();
      break;
    }

    switch(ch) {
    case 'i':
      pn += 1;
      break;
    case 'v':

      break;
    case 'x':
      break;
    case 'l':
      break;
    case 'c':
      break;
    case 'd':
      break;
    case 'm':
      break;
    }



  }
*/
