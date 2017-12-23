#ifndef PATRON_H
#define PATRON_H

//using namespace std;


class Patron {
public:
  Patron(string name, string number)
    :user_name(name), card_number(number), library_fees(0) {
  }

  const string& get_user_name() const { return user_name; }
  const string& get_card_number() const { return card_number; }
  double get_library_fees() const { return library_fees; }


  void set_library_fees(double fees) { library_fees = fees; }


private:
  string user_name;
  string card_number;
  double library_fees;
};


bool user_owes_fee(const Patron& p) {
  return (p.get_library_fees() > 0);
}

bool operator==(const Patron& a, const Patron& b) {
  return a.get_user_name() == b.get_user_name()  &&
    a.get_card_number() == b.get_card_number();
}


#endif
