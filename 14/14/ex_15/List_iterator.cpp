#include "List_iterator.hpp"

List_iterator::List_iterator(std::list<double>& ld)
  :_ld(ld), _index(ld.begin()) {
}


double *List_iterator::next() {
  if (_ld.size() == 0)
    return 0;

  if (_index != _ld.end())
    return &(*_index++);

  return 0;
}
