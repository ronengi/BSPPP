#include "Vector_iterator.hpp"

Vector_iterator::Vector_iterator(std::vector<double>& vd)
  :_vd(vd), _index(0) {
}


double *Vector_iterator::next() {
  if (_index < _vd.size())
    return &(_vd[_index++]);
  return 0;
}
