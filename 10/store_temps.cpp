#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

int randint(int max) {
  // return random between (0 - max)
  return rand() % (max + 1);
}
int rand_in_range(int a, int b) {
  // return random between (a - b)
  int max = (b > a) ? b : a;
  int min = (b < a) ? b : a;
  return randint(max - min) + min;
}


string i_to_m(int mm) {
  if (mm < 1  ||  12 < mm)    throw runtime_error("invalid month");
  static const string m_names[13] = { "", "jan", "feb", "mar", "apr", "may","jun", "jul", "aug", "sep", "oct", "nov", "dec"};
  //{ "", "Jan", "Feb", "Mar", "Apr", "May","Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"} };
  return m_names[mm];
}

void store_temps() {
  ofstream ofs("raw_temps");
  if (!ofs)    throw runtime_error("can't open output file");

  for (int years = 0; years < 3; ++years) {
    ofs << "{ year " << rand_in_range(1950, 2012) << endl;

    for (int months = 0; months < 3; ++months) {
      ofs << "\t{ month " << i_to_m(rand_in_range(1, 12)) << endl;

      for (int reading = 0; reading < 3; ++reading) {
	ofs << "\t\t ( " << rand_in_range(1, 31)
	    << "  " << rand_in_range(0, 23)
	    << "  " << rand_in_range(-10, 40) / 2.0
	    << " )\n";
      }	// reading

      ofs << "\t}\n";
    } // months

    ofs << "}\n";
  } // years


}


int main() {
  srand(time(NULL));		// initialize random seed

  store_temps();

}
