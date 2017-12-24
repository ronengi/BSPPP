#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
using namespace std;


struct Temp {
  double temp;
  Temp(double tt)
    :temp(tt) {
    if (temp < -50  ||  50 < temp)
      throw runtime_error("invalid temperature");
  }
  Temp()
    :temp(0) {}
};
struct Hour {
  int hour;
  Hour(int hh)
    :hour(hh) {
    if (hour < 0  ||  23 < hour)
      throw runtime_error("invalid hour");
  }
  Hour()
    :hour(0) {}
};
struct Day {
  int day;
  Day(int dd)
    :day(dd) {
    if (day < 1  ||  31 < day)
      throw runtime_error("invalid day");
  }
  Day()
    :day(1) {}
};
struct Month_name {
  int m_num;
  string m_name;

  void initialize(string mm) {
    static const string m_names[2][13] = { { "", "jan", "feb", "mar", "apr", "may","jun", "jul", "aug", "sep", "oct", "nov", "dec"},
					   { "", "Jan", "Feb", "Mar", "Apr", "May","Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"} };
    for (int i = 1; i <= 12; ++i) {
      if (mm == m_names[0][i]) {
  	m_num = i;
	m_name = m_names[1][i];
	return;
      }
    }
    throw runtime_error("illegal month name");
  }

  Month_name(string name) {
    initialize(name);
  }

  Month_name()
    :m_num(1), m_name("Jan") {}
};

struct Reading {
  Day day;
  Hour hour;
  Temp temp;
};
struct Month {
  Month_name month;
  vector<Reading> readings;
};
struct Year {
  int year;
  vector<Month> months;
};


istream& operator>>(istream& is, Reading& rr) {
  char ch;
  int d, h;
  double t;

  if (!(is >> ch  &&  ch == '(')) {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }

  is >> d >> h >> t >> ch;
  if (!(is  &&  ch == ')'))
    throw runtime_error("bad reading");

  rr.day = Day(d);
  rr.hour = Hour(h);
  rr.temp = Temp(t);
  return is;
}
ostream& operator<<(ostream& os, const Reading& rr) {
  return os << "\t\t\t( "
	    << rr.day.day << " "
	    << rr.hour.hour << " "
	    << rr.temp.temp << " "
	    << " )";
}

istream& operator>>(istream& is, Month& mm) {
  char ch;
  string m_marker, m_name;

  if (!(is >> ch  &&  ch == '{')) {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }

  is >> m_marker >> m_name;

  if (!(is  &&  m_marker == "month"))
    throw runtime_error("bad month");

  mm.month = Month_name(m_name);

  Reading rr;
  while (is >> rr)
    mm.readings.push_back(rr);

  // now try to read terminating '}'
  if (!is.fail()) 
    throw runtime_error("bad month");
  is.clear();
  if (!(is >> ch  &&  ch == '}'))
    throw runtime_error("bad month");

  return is;
}
ostream& operator<<(ostream& os, const Month& mm) {
  os << "\t{ month " << mm.month.m_name << endl;
  for (int i = 0; i < mm.readings.size(); ++i)
    os << mm.readings[i] << endl;
  os << "\t}";
  return os;
}

istream& operator>>(istream& is, Year& yy) {
  char ch;
  string y_marker;
  int y;

  if (!(is >> ch  &&  ch == '{')) {
    is.unget();
    is.clear(ios_base::failbit);
    return is;
  }

  is >> y_marker >> y;

  if (!(is  &&  y_marker == "year"))
    throw runtime_error("bad year");

  yy.year = y;

  Month mm;
  while (is >> mm) {
    yy.months.push_back(mm);
    mm.readings.clear();
  }

  // now try to read terminating '}'
  if (!is.fail()) 
    throw runtime_error("bad year");
  is.clear();
  if (!(is >> ch  &&  ch == '}'))
    throw runtime_error("bad year");

  return is;
}
ostream& operator<<(ostream& os, const Year& yy) {
  os << "{ year " << yy.year << endl;
  for (int i = 0; i < yy.months.size(); ++i)
    os << yy.months[i] << endl;
  os << "}";
  return os;
}



int main() {
  string i_name = "data";
  string o_name = "data.out";

  ifstream ifs(i_name.c_str());
  ofstream ofs(o_name.c_str());

  vector<Year> years;

  Year yy;
  while (ifs >> yy) {
    years.push_back(yy);
    yy.months.clear();
  }

  for (int i = 0; i < years.size(); ++i)
    ofs << years[i] << endl;

  ofs << endl;
  return 0;
}
