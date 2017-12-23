#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
using namespace std;

#include "ISBN.hpp"
#include "Chrono.hpp"

class Book {

public:
  enum Genre { fiction, nonfiction, periodical, biography, children };

  Book(ISBN _isbn, string _title, string _author, Chrono::Date _copyright, Genre _genre);


  const ISBN& get_isbn() const { return isbn; }
  const string& get_title() const { return title; }
  const string& get_author() const { return author; }
  const Chrono::Date& get_copyright() const { return copyright; }
  bool get_checked_out() const { return checked_out; }
  Genre get_genre() const { return genre; }

  bool check_in();
  bool check_out();


private:
  ISBN isbn;
  string title;
  string author;
  Chrono::Date copyright;
  bool checked_out;
  Genre genre;
};


ostream& operator<<(ostream& os, const Book& b);
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);


#endif
