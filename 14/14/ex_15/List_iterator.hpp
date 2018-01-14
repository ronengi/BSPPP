#ifndef LIST_ITERATOR_HPP
#define LIST_ITERATOR_HPP

#include <list>
#include "Iterator.hpp"


class List_iterator: public Iterator {
public:
  List_iterator(std::list<double>& ld);
  double *next();
private:
  std::list<double>& _ld;
  std::list<double>::iterator _index;
};



#endif
