// Library classes (ex 5 - 9, p.334-5)
// not fully checked
// functionality not complete for production


#include "Library.hpp"


int Library::patron_in_library(const Patron& p) {
  for (unsigned int i = 0; i < patrons.size(); ++i) {
    if (patrons[i] == p)
      return i;
  }
  throw runtime_error("user not in library");
  return -1;
}

int Library::book_in_library(const Book& b) {
  for (unsigned int i = 0; i < books.size(); ++i) {
    if (books[i] == b)
      return i;
  }
  throw runtime_error("book not in library");
  return -1;
}

void Library::check_out_book(Book b, Patron p) {
  int ipatron = patron_in_library(p), ibook = book_in_library(b);
  if (user_owes_fee(p))    throw runtime_error("user in debt");
  books[ibook].check_out();
  transactions.push_back(Transaction(ibook, ipatron)); 
}

void Library::list_owed_patrons() {
  cout << "Users with debts:\n";
  for (unsigned int i = 0; i < patrons.size(); ++i) {
    if (user_owes_fee(patrons[i]))
	cout << patrons[i].get_user_name() << endl;
  }
}






int main() {

  Library l1;

  Book b1(ISBN(1, 2, 3, 'a'), "book1", "author1", Chrono::Date(), Book::fiction);

  cout << "The Book:\n" << b1 << endl;

  Patron p1("moshe", "12345");


  //Library::Transaction t1(b1, p1, Chrono::Date());


  return 0;
}
