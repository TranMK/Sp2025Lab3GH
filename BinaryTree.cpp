#include "BinaryTree.hpp"
#include <string>
#pragma once

template <typename T> void BinaryTree<T>::Insert(T inVal){
    TreeNode<T> *newNode = nullptr;  
    
    newNode = new TreeNode;
    newNode->value = inVal;
    newNode->left = newNode->right = nullptr;
    insertpriv(root, newNode);
    size++;
}
template <typename T> void BinaryTree<T>::insertpriv(TreeNode<T> *&nodePtr, TreeNode<T> *&newNode){
    if(nodePtr == nullptr){
        nodePtr = newNode; //insert new node
        update(newNode);
        balance(newNode);
    }else if(newNode->getValue()==nodePtr->getValue()){
        nodePtr->incCount(); //doesn't insert, increase count
    }else if(newNode->getValue() < nodePtr->getValue()){
        insertpriv(nodePtr->left, newNode); //search left branch
    }else{
        insertpriv(nodePtr->right, newNode); //search right branch
    }
}
template <typename T> void BinaryTree<T>::update(TreeNode<T>* node){
    int lh = -1;
    int rh = -1;
    if(node->left!=nullptr){lh = node->left->height;}
    if(node->right!=nullptr){rh = node->right->height;}
    node->height = 1+std::max(lh,rh);
    node->balfac = rh - lh;
}
template <typename T> TreeNode<T>* BinaryTree<T>::balance(TreeNode<T>* node){
    if(node->balfac == -2){
        if(node->left->balfac <= 0){
            return rotateLL(node);
        }else{
            return rotateLR(node);
        }
    }else if(node->balfac == 2){
        if(node->left->balfac >= 0){
            return rotateRR(node);
        }else{
            return rotateRL(node);
        }
    }
    return node;
}
template <typename T> TreeNode<T>* BinaryTree<T>::leftRotate(TreeNode<T>* node){
    TreeNode<T>* child = node->left;
    node->left = child->right;
    child->right = node;
    update(node);
    update(child);
    return child;
}
template <typename T> TreeNode<T>* BinaryTree<T>::rightRotate(TreeNode<T>* node){
    TreeNode<T>* child = node->right;
    node->right = child->left;
    child->left = node;
    update(node);
    update(child);
    return child;
}
template <typename T> bool BinaryTree<T>::Find(T inVal){
    return findSub(root, inVal);
}
template <typename T> bool BinaryTree<T>::findSub(TreeNode<T>* node, T inVal){
    if(node==nullptr){//no value found
        return false;
    }else if(node->getValue()==inVal){//value found
        return true;
    }else if(node->getValue() < inVal){//go right
        return findSub(node->right, inVal);
    }else{//go left
        return findSub(node->left, inVal);
    }
}
template <typename T> TreeNode<T>* BinaryTree<T>::Remove(T inVal){
    TreeNode<T>* removedNode = nullptr;
    root = removeSubnode(root, inVal, removedNode);
    if(removedNode != nullptr){
        size--;
    }
    return removedNode;//caller must delete the removed node
}
template <typename T> TreeNode<T>* BinaryTree<T>::removeSubnode(TreeNode<T>* node, T inVal, TreeNode<T>*& removedNode){
    if (node == nullptr) return nullptr;

    TreeNode<T>* retNode = node;

    if (inVal < node->value){//go left
        node->left = removeSub(node->left, inVal, removedNode);
    }else if(inVal > node->value){//go right
        node->right = removeSub(node->right, inVal, removedNode);
    }else{
        //node found, store for return before removal
        removedNode = new TreeNode<T>(*node);//make copy to return
        removedNode->left = removedNode->right = nullptr;//don't copy children into returning node

        if(node->left == nullptr && node->right == nullptr){//leaf
            delete node;
            retNode = nullptr;
        }
        else if(node->left == nullptr){//only has right child
            retNode = node->right;
            delete node;
        }
        else if(node->right == nullptr){//only has left child
            retNode = node->left;
            delete node;
        }
        else{//two children
            TreeNode<T>* successor = (node->left->height > node->right->height)
                ? leftLargest(node->left) : rightSmallest(node->right);
            node->value = successor->value;
            node->count = successor->count;

            if(node->left->height > node->right->height){
                node->left = removeSub(node->left, successor->value, removedNode);
            }else{
                node->right = removeSub(node->right, successor->value, removedNode);
            }
            retNode = node;
        }
    }
    if(retNode != nullptr){
        update(retNode);
        retNode = balance(retNode);
    }
    return retNode;

    // if(node==nullptr){return nullptr;}
    // if(node->getValue() > inVal){//go left
    //     node->left = removeSub(node->left, inVal);
    // }else if(node->getValue() < inVal){//go right
    //     node->right = removeSub(node->right, inVal);
    // }else{//node found
    //     if(node->left==nullptr){//sub with right child
    //         return node->right;
    //     }else if(node->right==nullptr){//sub with left child
    //         return node->left;
    //     }else{
    //         //remove nodes from left child or right child based on subtree height
    //         if(node->left->height > node->right->height){//remove from left child
    //             TreeNode<T> successor = leftLargest(node->left);
    //             node->value=successor->getValue();
    //             node->count=successor->getCount();

    //             node->left = remove(node->left, successor->getValue());
    //         }else{//remove from right child
    //             TreeNode<T> successor = rightSmallest(node->right);
    //             node->value=successor->getValue();
    //             node->count=successor->getCount();

    //             node->right = remove(node->right, successor->getValue());
    //         }
    //     }
    // }
    // update(node);
    // return balance(node);
}
template <typename T> TreeNode<T>* BinaryTree<T>::leftLargest(TreeNode<T>* node){
    //finds node with largest value on the left on a passed node's left child(for Remove)
    while(node->right != nullptr){
        node = node->right;
    }
    return node;//we only need the node's value and count, so pointers aren't needed for simplicity
}
template <typename T> TreeNode<T>* BinaryTree<T>::rightSmallest(TreeNode<T>* node){
     //finds node with largest value on the left on a passed node's right child(for Remove)
     while(node->left != nullptr){
        node = node->left;
    }
    return node;//we only need the node's value and count, so pointers aren't needed for simplicity
}
template <typename T>
std::vector<T> BinaryTree<T>::GetAllAscending() {
    //returns array of pointers to nodes with value in ascending order
    std::vector<TreeNode<T>*> result;
    GetAllAscendingRecursive(root, result);
    return result;
}

template <typename T>
void BinaryTree<T>::GetAllAscendingRecursive(TreeNode<T>* node, std::vector<TreeNode<T>*>& result) {
    if (node == nullptr) return;  // base case

    GetAllAscendingRecursive(node->left, result);  // go left
    result.push_back(node);            // pushes back pointer to node
    GetAllAscendingRecursive(node->right, result); // go right
}
template <typename T>
std::vector<T> BinaryTree<T>::GetAllDescending() {
    //returns array of pointers to node with value in descending order
    std::vector<TreeNode<T>*> result;
    GetAllDescendingRecursive(root, result);
    return result;
}

template <typename T>
void BinaryTree<T>::GetAllDescendingRecursive(TreeNode<T>* node, std::vector<TreeNode<T>*>& result) {
    if (node == nullptr) return;  // base case

    GetAllDescendingRecursive(node->left, result);  // go left
    result.push_back(node);            // pushes back pointer to node
    GetAllDescendingRecursive(node->right, result); // go right
}
template <typename T> void BinaryTree<T>::EmptyTree(){
    removeSubtree(root);
    root = nullptr;
    size = 0;
}
template <typename T> void BinaryTree<T>::removeSubtree(TreeNode<T>* node){
    //deletes an entire subtree starting from the inputted node
    if (node == nullptr) return;
    //post-order traversal to delete child nodes first
    removeSubtree(node->left);
    removeSubtree(node->right);
    delete node;
}
template class TreeNode<std::string>;
template class BinaryTree<std::string>;