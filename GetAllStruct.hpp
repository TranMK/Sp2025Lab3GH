#include "Node.hpp"

#pragma once

template <typename T> class GetAllStruct {
public:
  Node<T> *Node;
  int Level;
  int BalFac;

  GetAllStruct(::Node<T> *inNode, int lvl, int BF)
      : Node(inNode), Level(lvl), BalFac(BF) {}
};
