#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

#include "Chrono.hpp"
#include "Book.hpp"
#include "ISBN.hpp"
#include "Patron.hpp"

class Library {
  struct Transaction {
    Transaction(int _ibook, int _ipatron)
      :ibook(_ibook), ipatron(_ipatron), date(Chrono::Date()) {
      // date should be today instead of default...
    } 
    int ibook;
    int ipatron;
    Chrono::Date date;
  };
public:
  Library() {}
  void add_book(Book b) { books.push_back(b); }
  void add_patron(Patron p) { patrons.push_back(p); }
  void check_out_book(Book b, Patron p);
  void list_owed_patrons();
  int patron_in_library(const Patron& p);
  int book_in_library(const Book& b);
private:
  vector<Book> books;
  vector<Patron> patrons;
  vector<Transaction> transactions;
};


#endif
