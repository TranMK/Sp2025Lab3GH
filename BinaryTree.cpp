#include <algorithm>
#include <iostream>

#include "BinaryTree.hpp"
#include "errors.hpp"
using namespace std;

template <typename T> void Tree<T>::Insert(T inVal) {
  Node<T> *temp = root;
  if (root == nullptr) { // empty
    root = new Node(inVal);
    return;
  }

  while ((inVal > temp->data && temp->right != nullptr) ||
         (inVal <= temp->data && temp->left != nullptr)) {
    // Wants to go left & can go left, or wants to go right and can go right
    if (inVal > temp->data) {
      temp = temp->right;
    } else {
      temp = temp->left;
    }
    // Which direction to go
  }

  if (inVal > temp->data) {
    temp->right = new Node(inVal);
  } else {
    temp->left = new Node(inVal);
  }
}

template <typename T> auto Tree<T>::Find(T target) -> T {
  if (root == nullptr) {
    throw NotFoundError{};
  }

  Node<T> *temp = root;
  while (temp != nullptr & target != temp->data) {
    if (target < temp->data) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }

  if (temp != nullptr) {
    throw NotFoundError{};
  }

  return temp->data;
}

template <typename T> void Tree<T>::Print() { PrintSub(root); }

template <typename T> void Tree<T>::PrintSub(Node<T> *place) {
  if (place == nullptr)
    return;

  PrintSub(place->right);
  std::cout << place->data << ", ";
  std::cout << std::endl;
  PrintSub(place->left);
}

template <typename T> void Tree<T>::PrintS(Node<T> *place) {
  if (place == nullptr)
    return;

  std::cout << place->data << "(";
  if (place->left == nullptr) {
    std::cout << "_";
  } else {
    std::cout << place->left->data;
  }
  std::cout << ", ";
  if (place->right == nullptr) {
    std::cout << "_";
  } else {
    std::cout << place->right->data;
  }
  std::cout << ")";
}

template <typename T> auto Tree<T>::Remove(T inVal) -> T {
  Find(inVal); // check if in Tree
  Node<T> *temp = root;
  if (root->data == inVal) {                              // remove root
    if (root->left == nullptr & root->right == nullptr) { // leaf
    }
    if (root->left != nullptr) { // 1 child
      temp = root->left;
      delete root;
      root = temp;
    }
  }
  while ((temp->data > inVal & temp->left->data != inVal) |
         (temp->data <= inVal & temp->right->data != inVal)) {
    if (temp->data > inVal) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  } // Loop until temp is pointing towards parent with value to find in children
  if (inVal < temp->data) { // leaf
    char outVal = temp->left->data;
    delete temp->left;
    temp->left = nullptr;
    return outVal;
  } else {
    char outVal = temp->right->data;
    delete temp->right;
    temp->right = nullptr;
    return outVal;
  }
  // Case:Node with 1 child, removing one child
  if (inVal < temp->data & temp->left->left == nullptr &
      temp->left->right == nullptr) {
    // Remove left leaf
    char outVal = temp->left->data;
    delete temp->left;
    temp->left = nullptr;
    return outVal;
  } else if (temp->data <= inVal & temp->right->left == nullptr &
             temp->right->right == nullptr) {
    // Remove right leaf
    char outVal = temp->right->data;
    delete temp->right;
    temp->right = nullptr;
    return outVal;
    // Remove node with 1 child
  } else if ((temp->data > inVal) &
             (temp->left->left == nullptr | temp->left->right == nullptr)) {
    // Removes the left child
    char outVal = temp->left->data;
    Node<T> *child = temp->left;
    if (child->left != nullptr) {
      temp->left = child->left;
    } else {
      temp->left = child->right;
    }
    delete child;
    return outVal;
  } else if ((temp->data <= inVal) &
             (temp->right->left == nullptr | temp->right->right == nullptr)) {
    // Removes the right child
    char outVal = temp->right->data;
    Node<T> *child = temp->right;
    if (child->left != nullptr) {
      temp->right = child->left;
    } else {
      temp->right = child->right;
    }
    delete child;
    return outVal;
  } else if (temp->data >
             inVal) { // Two children of node, parent on right of child
    char replace = LeftLargest(temp->left);
    Remove(replace);
    int retVal = temp->left->data;
    temp->left->data = replace;
    return retVal;
  } else if (temp->data <=
             inVal) { // Two children of node, parent on left of child
    char replace = LeftLargest(temp->right);
    Remove(replace);
    int retVal = temp->right->data;
    temp->right->data = replace;
    return retVal;
  }
}

template <typename T> auto Tree<T>::LeftLargest(Node<T> *parent) -> T {
  Node<T> *temp = parent->left;
  while (temp->right != nullptr) {
    temp = temp->right;
  }
  return temp->data;
}

template <typename T>
void Tree<T>::RotateLeft(Node<T> *parent, Node<T> *child) {
  if (root == child) { // child is root
    root = child->right;
    child->right = root->left;
    root->left = child;
  }
  if (parent->right == child) {
    parent->right = child->right;
    child->right = parent->right->left;
    parent->right->left = child;
  } else {
    parent->left = child->right;
    child->right = parent->left->left;
    parent->left->left = child;
  }
}

template <typename T>
void Tree<T>::RotateRight(Node<T> *parent, Node<T> *child) {
  if (root == child) { // child is root
    root = child->left;
    child->left = root->right;
    root->right = child;
  } else if (parent->right == child) {
    parent->right = child->left;
    child->left = parent->right->right;
    parent->right->right = child;
  } else {
    parent->left = child->left;
    child->left = parent->left->right;
    parent->left->right = child;
  }
}

template <typename T> void Tree<T>::RotateRL(Node<T> *parent, Node<T> *child) {
  // assumes parent->right points to A, A->right=C, C->left=B; B->left=B-;
  // B->right=B+
  if (child == root) {                // child is root
    root = child->right->left;        // root points to B
    child->right->left = root->right; // C left points to B+
    root->right = child->right;       // B right points to C
    child->right = root->left;        // A right points to B-
    root->left = child;               // B left points to A
  } else if (parent->right == child) {
    parent->right = child->right->left;        // parent right points to B
    child->right->left = parent->right->right; // C left points to B+
    parent->right->right = child->right;       // B right points to C
    child->right = parent->right->left;        // A right points to B-
    parent->right->left = child;               // B left points to A
  } else {
    // assumes parent->left points to A, A->right=C, C->left=B; B->left=B-;
    // B->right=B+
    parent->left = child->right->left;        // parent left points to B
    child->right->left = parent->left->right; // C left points to B+
    parent->left->right = child->right;       // B right points to C
    child->right = parent->left->left;        // A right points to B-
    parent->left->left = child;               // B left points to A
  }
}

template <typename T> void Tree<T>::RotateLR(Node<T> *parent, Node<T> *child) {
  // assumes parent->right points to C, C->left=A, A->right=B; B->left=B-;
  // B->right=B+
  if (child == root) {               // child is root
    root = child->left->right;       // parent points to B
    child->left->right = root->left; // A right points to B-
    root->left = child->left;        // B left points to A
    child->left = root->right;       // C left points to B+
    root->right = child;             // B right points to C
  } else if (parent->right == child) {
    parent->right = child->left->right;       // parent right points to B
    child->left->right = parent->right->left; // A right points to B-
    parent->right->left = child->left;        // B left points to A
    child->left = parent->right->right;       // C left points to B+
    parent->right->right = child;             // B right points to C
  } else {
    // assumes parent->left points to C, C->left=A, A->right=B; B->left=B-;
    // B->right=B+
    parent->left = child->left->right;       // parent left points to B
    child->left->right = parent->left->left; // A right points to B+
    parent->left->left = child->left;        // B left points to A
    child->left = parent->left->right;       // C left points to B+
    parent->left->right = child;             // B left points to C
  }
}

template <typename T>
auto Tree<T>::Levels(Node<T> *parent, Node<T> *child)
    -> int { // counts number of lines below
  if (child == nullptr) {
    return 0;
  }

  int L = Levels(child, child->left);
  int R = Levels(child, child->right);
  if (L - R > 1) {
    if (Levels(child->left, child->left->left) >
        Levels(child->left, child->left->right)) {
      RotateRight(parent, child);
    } else {
      RotateLR(parent, child);
    }
  } else if (R - L > 1) {
    if (Levels(child->right, child->right->left) >
        Levels(child->right, child->right->right)) {
      RotateLeft(parent, child);
    } else {
      RotateRL(parent, child);
    }
  }

  if (L > R)
    return L + 1;
  return R + 1;
}

template <typename T>
auto Tree<T>::GetAllAscending(Node<T> *parent) -> std::vector<Node<T> *> {
  if (parent == nullptr)
    return {};

  std::vector<Node<T> *> nodes = {};
  // Left subtree.
  auto left_subtree_nodes = GetAllAscending(parent->left);
  if (left_subtree_nodes != std::vector<Node<T> *>{}) {
    for (auto node : left_subtree_nodes) {
      nodes.push_back(node);
    }
  }

  // Add self.
  nodes.push_back(parent);

  // Right subtree.
  auto right_subtree_nodes = GetAllAscending(parent->right);
  if (right_subtree_nodes != std::vector<Node<T> *>{}) {
    for (auto node : right_subtree_nodes) {
      nodes.push_back(node);
    }
  }
  for(Node<T> node: nodes){
    cout<<node->data<<"    "<<Levels(node, node)<<"    "<<Levels(node, node->left)
      -Levels(node, node->right)<<endl;
  }
  return nodes;
}

template <typename T>
auto Tree<T>::GetAllDescending(Node<T> *parent) -> std::vector<Node<T> *> {
  std::vector<Node<T> *> nodes = GetAllAscending(parent);
  std::reverse(nodes.begin(), nodes.end());
  for(Node<T> node: nodes){
    cout<<node->data<<"    "<<Levels(node, node)<<"    "<<Levels(node, node->left)
      -Levels(node, node->right)<<endl;
  }
  return nodes;
}

// template class Tree<std::string>;
