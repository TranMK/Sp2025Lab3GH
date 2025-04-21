#pragma once
template <typename T> class TreeNode {
  public:
      T value;
      int count;
      TreeNode* left;//left child
      TreeNode* right; //right child
      int height; //height
      int balancefactor;//balance factor
  
      // Constructor to initialize a node with a given value
      TreeNode(T k): value(k), left(nullptr), right(nullptr), height(1), count(1)
      {
      }
  };