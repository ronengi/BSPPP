#ifndef BINARY_TREE_1_HPP
#define BINARY_TREE_1_HPP

#include "/home/blanca/bs_ppp/bs_fltk/Simple_window.h"
#include "/home/blanca/bs_ppp/bs_fltk/Graph.h"

#include "Binary_tree.hpp"



class Binary_tree_1 : public Binary_tree {
public:
  Binary_tree_1(int levels) : Binary_tree(levels) {}
  void draw_lines() const;
};



#endif

