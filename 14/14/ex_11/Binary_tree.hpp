#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"


class Binary_tree : public Shape {
public:
  Binary_tree(int levels);
  void draw_lines() const;

private:
  int _levels;
};



#endif

