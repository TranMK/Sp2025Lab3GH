#include <algorithm>
#include <iostream>
#include <vector>

#include "BinaryTree.hpp"
#include "errors.hpp"
#include "GetAllStruct.hpp"
using namespace std;

template <typename T> auto Tree<T>::Insert(Node<T>* node, T inVal)->Node<T>*{
  if (!root) {//doesn't exist
    return new Node(inVal);
  }
  if(inVal<node->data){//go left
    node->left=Insert(node->left,inVal);
    Levels(nullptr, root);
  }else if(inVal>node->data){//go right
    node->right=Insert(node->right,inVal);
    Levels(nullptr, root);
  }else{//already exists
    node->count+=1;
  }
  size++;
  return node;
}

template <typename T> auto Tree<T>::Find(T target) -> Node<T>* {
  return FindSub(target, root);
}
template <typename T> auto Tree<T>::FindSub(T target, Node<T>* node)->Node<T>*{
  if(node->data==target||node==nullptr){
    return node;
  }else{
    if(target < node->data){
      return FindSub(target,node->left);
    }else{
      return FindSub(target,node->right);
    }
  }
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
/*
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
  while ((temp->data > inVal && temp->left->data != inVal) ||
         (temp->data <= inVal && temp->right->data != inVal)) {
    if (temp->data > inVal) {
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  } // Loop until temp is pointing towards parent with value to find in children
  if (inVal < temp->data) { // leaf
    std::string outVal = temp->left->data;
    delete temp->left;
    temp->left = nullptr;
    return outVal;
  } else {
    std::string outVal = temp->right->data;
    delete temp->right;
    temp->right = nullptr;
    return outVal;
  }
  // Case:Node with 1 child, removing one child
  if (inVal < temp->data & temp->left->left == nullptr &
      temp->left->right == nullptr) {
    // Remove left leaf
    std::string outVal = temp->left->data;
    delete temp->left;
    temp->left = nullptr;
    return outVal;
  } else if (temp->data <= inVal & temp->right->left == nullptr &
             temp->right->right == nullptr) {
    // Remove right leaf
    std::string outVal = temp->right->data;
    delete temp->right;
    temp->right = nullptr;
    return outVal;
    // Remove node with 1 child
  } else if ((temp->data > inVal) &
             (temp->left->left == nullptr | temp->left->right == nullptr)) {
    // Removes the left child
    std::string outVal = temp->left->data;
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
    std::string outVal = temp->right->data;
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
    std::string replace = LeftLargest(temp->left)->data;
    Remove(replace);
    std::string retVal = temp->left->data;
    temp->left->data = replace;
    return retVal;
  } else if (temp->data <=
             inVal) { // Two children of node, parent on left of child
    std::string replace = LeftLargest(temp->right)->data;
    Remove(replace);
    std::string retVal = temp->right->data;
    temp->right->data = replace;
    return retVal;
  }
}
*/
template <typename T> auto Tree<T>::Remove(T inVal) -> Node<T>* {
  //finds the temp1 to delete, finds the temp2 that's the largest on its left, 
  //assign temp2's value and count to temp1, delete temp2, attach node2's left child(if any) to its parent
  /*Node<T>* temp1 = Find(inVal);
  if(temp1->left==nullptr&&temp1->right==nullptr){//remove root
    Node<T>* retNode = temp1;
    root=nullptr;
    return retNode;
  }
  Node<T>* temp2 = LeftLargest(temp1);//largest value left of temp1
  if(temp2->left!=nullptr){//node to replace with has left child
    //temp1->data=temp2->data;
    //temp1->count=temp2->count;//transfers count and value
    Node<T>* loopNode = temp1->left;
    while(loopNode->right!=temp2||loopNode->right!=nullptr){//either loopNode is temp2's parent, or temp1's child
      loopNode=loopNode->right;
    }
    if(loopNode->right==nullptr){//temp1's child
      Node<T>* midman = loopNode;
      midman->data=temp1->data;
      midman->count=temp1->count;
      temp1->data=loopNode->data;
      temp1->count=loopNode->count;
      loopNode->data=midman->data;
      
    }
    delete temp2;
    loopNode->right=nullptr;
  }else{//node to replace has no left child

  }*/
  return RemoveSub(inVal,root);
  size--;

}
template <typename T> auto Tree<T>::RemoveSub(T inVal, Node<T>* node)->Node<T>*{
  if(node==nullptr){
    return node;
  }
  if(inVal<node->data){
    node->left=RemoveSub(inVal,node->left);
  }else if(inVal>node->data){
    node->right=RemoveSub(inVal,node->right);
  }else{
    if(node->left==nullptr){//has right child
      Node<T>* temp=node->right;
      delete node;
      return temp;
    }else if(node->right==nullptr){//has left child
      Node<T>* temp=node->left;
      delete node;
      return temp;
    }else{//2 children
      Node<T>* LargestLeft = LeftLargest(node);//finds largest node smaller than input node
      node->data=LargestLeft->data;
      node->count=LargestLeft->count;
      node->right=RemoveSub(LargestLeft->data,node->right);
    }
  }
  Levels(nullptr,root);
  return node;
}
template <typename T> void Tree<T>::EmptyTree(Node<T>* node){
  if(!node) return;
  EmptyTree(node->left);
  EmptyTree(node->right);
  delete node;
  size=0;
}
template <typename T> auto Tree<T>::LeftLargest(Node<T> *parent) -> Node<T> * {
  Node<T> *temp = parent->left;
  while (temp->right != nullptr) {
    temp = temp->right;
  }
  return temp;
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
  } else if (parent->left == child) {
    parent->left = child->right;
    child->right = parent->left->left;
    parent->left->left = child;
  }
}

template <typename T>
void Tree<T>::RotateRight(Node<T> *parent, Node<T> *child) {
  if (root == child) { // child is root
    root = child->left;
    if(root->right != nullptr) {
      child->left = root->right;
    } else {
      child->left = nullptr;
    }
    root->right = child;
  } else if (parent->right == child) {
    parent->right = child->left;
    if (parent->right->right!=nullptr) {
      child->left = parent->right->right;
    } else{
      child->left = nullptr;
    }
    parent->right->right=child;
  } else if (parent->left == child) {
    parent->left = child->left;
    if (parent->left->right!=nullptr) {
      child->left = parent->left->right;
      parent->left->right = child;
    } else {
      child->left = nullptr;
      parent->left->right = child;
      
    }
    
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
auto Tree<T>::Levels(Node<T> *parent, Node<T> *child) -> int {
    if (child == nullptr) {
        return 0;
    }

    int L = Levels(child, child->left);
    int R = Levels(child, child->right);

    if (L - R > 1) {
        if (child->left != nullptr && Levels(child->left, child->left->left) >
                                      Levels(child->left, child->left->right)) {
            RotateRight(parent, child);
        } else if (child->left != nullptr) {
            RotateLR(parent, child);
        }
    } else if (R - L > 1) {
        if (child->right != nullptr && Levels(child->right, child->right->left) >
                                       Levels(child->right, child->right->right)) {
            RotateLeft(parent, child);
        } else if (child->right != nullptr) {
            RotateRL(parent, child);
        }
    }

    return std::max(L, R) + 1;
}

template <typename T>
auto Tree<T>::GetAll(Node<T> *parent) -> std::vector<Node<T> *> {
  if (parent == nullptr)
    return {};

  std::vector<Node<T> *> nodes = {};
  // Left subtree.
  auto left_subtree_nodes = GetAll(parent->left);
  if (left_subtree_nodes != std::vector<Node<T> *>{}) {
    for (auto node : left_subtree_nodes) {
      nodes.push_back(node);
    }
  }

  // Add self.
  nodes.push_back(parent);

  // Right subtree.
  auto right_subtree_nodes = GetAll(parent->right);
  if (right_subtree_nodes != std::vector<Node<T> *>{}) {
    for (auto node : right_subtree_nodes) {
      nodes.push_back(node);
    }
  }
  return nodes;
}
template <typename T>
auto Tree<T>::GetAllAscending() -> std::vector<GetAllStruct<T>*> {
    std::vector<Node<T> *> inVect = GetAll(this->root);
    std::vector<GetAllStruct<T> *> outVect;
    for (auto node : inVect) {
        outVect.push_back(
            new GetAllStruct<T>(
              node, Levels(node, node), Levels(node, node->left) - Levels(node, node->right))
        );
        std::cout<<Levels(node, node)<<"  "<<Levels(node, node->left)-Levels(node, node->right)<<std::endl;
    }
    return outVect;
}
template <typename T>
auto Tree<T>::GetAllDescending() -> std::vector<GetAllStruct<T>*> {
    std::vector<Node<T> *> inVect = GetAll(this->root);
    std::reverse(inVect.begin(), inVect.end());
    std::vector<GetAllStruct<T> *> outVect;
    for (auto node : inVect) {
        outVect.push_back(
            new GetAllStruct<T>(
              node, Levels(node, node), Levels(node, node->left) - Levels(node, node->right))
        );
        std::cout<<Levels(node, node)<<"  "<<Levels(node, node->left)-Levels(node, node->right)<<std::endl;
    }
    return outVect;
}
template class Tree<std::string>;
template class GetAllStruct<std::string>;
