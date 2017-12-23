#include "Book.hpp"


Book::Book(ISBN _isbn, string _title, string _author, Chrono::Date _copyright, Genre _genre)
  :isbn(_isbn), title(_title), author(_author), copyright(_copyright), checked_out(false), genre(_genre) {
}

bool Book::check_in() {
  if (!checked_out)
    return false;
  else
    checked_out = false;
  return true;
}
bool Book::check_out() {
  if (checked_out)
    return false;
  else
    checked_out = true;
  return true;
}


ostream& operator<<(ostream& os, const Book& b) {
  string chot = (b.get_checked_out()) ? "Yes" : "No";
  string gnr;

  switch (b.get_genre()) {
  case Book::fiction:
    gnr = "Fiction";
    break;
  case Book::nonfiction:
    gnr = "Non-Fiction";
    break;
  case Book::periodical:
    gnr = "Periodical";
    break;
  case Book::biography:
    gnr = "Biography";
    break;
  case Book::children:
    gnr = "Children";
    break;
  }

  return os << "Title: " << b.get_title() << endl
	    << "Author: " <<  b.get_author() << endl
	    << "ISBN: " << b.get_isbn() << endl
	    << "Copyright Date: " <<  b.get_copyright() << endl
	    << "Checked out: " << chot << endl
	    << "Genre: " << gnr << endl
	    << endl;
}
bool operator==(const Book& a, const Book& b) {
  return a.get_isbn() == b.get_isbn();
}
bool operator!=(const Book& a, const Book& b) {
  return !(a == b);
}
