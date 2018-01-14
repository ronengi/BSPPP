#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <vector>
#include "Iterator.hpp"


class Vector_iterator: public Iterator {
public:
  Vector_iterator(std::vector<double>& vd);
  double *next();
private:
  std::vector<double>& _vd;
  int _index;
};



#endif
