#include "BinaryTree.hpp"
#include "errors.hpp"
#include <string>
#include <iostream>
//get height of node
template <typename T> int BinaryTree<T>::height(TreeNode<T>* node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

//get balance factor of node
template <typename T> int BinaryTree<T>::balancefactor(TreeNode<T>* node)
{
    if (node == nullptr)
        return 0;
    node->balancefactor = height(node->left) - height(node->right);
    return node->balancefactor;
}

// right rotation
template <typename T> TreeNode<T>* BinaryTree<T>::rightrotate(TreeNode<T>* node)
{
    TreeNode<T>* leftchild = node->left;
    TreeNode<T>* c2 = leftchild->right;

    leftchild->right = node;
    node->left = c2;

    // update heights
    node->height
        = max(height(node->left), height(node->right)) + 1;
    leftchild->height
        = max(height(leftchild->left), height(leftchild->right)) + 1;

    // return new root
    return leftchild;
}

// left rotation
template <typename T> TreeNode<T>* BinaryTree<T>::leftrotate(TreeNode<T>* node)
{
    TreeNode<T>* rightchild = node->right;
    TreeNode<T>* c2 = rightchild->left;

    rightchild->left = node;
    node->right = c2;

    // update heights
    node->height
        = max(height(node->left), height(node->right)) + 1;
        rightchild->height
        = max(height(rightchild->left), height(rightchild->right)) + 1;

    // return new root
    return rightchild;
}

// function to insert a new value into the subtree rooted
// with node
template <typename T> TreeNode<T>* BinaryTree<T>::insertrecursive(TreeNode<T>* node, T value)
{
    // Normal BST insertion
    if (node == nullptr){
        size++;
        return new TreeNode<T>(value);
    }
    if (value < node->value)
        node->left = insertrecursive(node->left, value);
    else if (value > node->value)
        node->right = insertrecursive(node->right, value);
    else if (value == node->value){
        node->count++;
        return node;
    }else{
        return node;
    }

    // update height of parent node
    node->height = 1
                   + max(height(node->left),
                         height(node->right));

    // Get balance factor of parent node
    int balance = balancefactor(node);

    // If this node becomes unbalanced, 4 unbalanced cases

    // left left Case
    if (balance > 1 && value < node->left->value)
        return rightrotate(node);

    // right right Case
    if (balance < -1 && value > node->right->value)
        return leftrotate(node);

    // left right Case
    if (balance > 1 && value > node->left->value) {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    // right left Case
    if (balance < -1 && value < node->right->value) {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

// find the node with the maximum value and smaller than the node inputted
template <typename T> TreeNode<T>* BinaryTree<T>::leftlargest(TreeNode<T>* node)
{
    TreeNode<T>* current = node;
    while (current->right != nullptr)
        current = current->right;
    return current;
}

// function to delete a value from the subtree rooted with
// root
template <typename T> TreeNode<T>* BinaryTree<T>::deleterecursive(TreeNode<T>* root, T value, TreeNode<T>*& removedNode)
{
    // Standard BST delete
    if (root == nullptr)
        return root;

    if (value < root->value)
        root->left = deleterecursive(root->left, value, removedNode);
    else if (value > root->value)
        root->right = deleterecursive(root->right, value, removedNode);
    else {
        removedNode = new TreeNode<T>(*root);
        removedNode->left = nullptr;
        removedNode->right = nullptr;//save removedNode
        size--;

        // Node with only one child or no child
        if ((root->left == nullptr)
            || (root->right == nullptr)) {
            TreeNode<T>* temp
                = root->left ? root->left : root->right;
            delete root;
            return temp;
        }
        else {

            TreeNode<T>* temp
                = leftlargest(root->left);
            root->value = temp->value;
            root->count = temp->count;
            temp->count = 1;
            root->right
                = deleterecursive(root->right, temp->value, removedNode);
        }
    }

    if (root == nullptr)
        return root;

    // Update height of parent node
    root->height = 1 + max(height(root->left), height(root->right));

    // Get the balance factor of parent node
    int balance = balancefactor(root);

    // If this node becomes unbalanced, 4 unbalanced cases

    // left left Case
    if (balance > 1 && balancefactor(root->left) >= 0)
        return rightrotate(root);

    // left right Case
    if (balance > 1 && balancefactor(root->left) < 0) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // right right Case
    if (balance < -1 && balancefactor(root->right) <= 0)
        return leftrotate(root);

    // right left Case
    if (balance < -1
        && balancefactor(root->right) > 0) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

// // function to perform inorder traversal of the tree
template <typename T> void BinaryTree<T>::inorder(TreeNode<T>* root)
{
    if (root != nullptr) {
        inorder(root->left);
        cout << root->value<<"  "<<root->count<<'\n';
        inorder(root->right);
    }
}

// function to search for a value in the subtree rooted
// with root
template <typename T> TreeNode<T>* BinaryTree<T>::findrecursive(TreeNode<T>* root, T value)
{
    if (root == nullptr)
        return nullptr;
    if (root->value == value)
        return root;
    if (value < root->value)
        return findrecursive(root->left, value);
    return findrecursive(root->right, value);
}
template <typename T> void BinaryTree<T>::ascendingrecursive(std::vector<TreeNode<T>*> &retArr, TreeNode<T>* node){
    if(node == nullptr){return;}
    ascendingrecursive(retArr, node->left);
    retArr.push_back(node);
    ascendingrecursive(retArr, node->right);
    return;
}
template <typename T> void BinaryTree<T>::descendingrecursive(std::vector<TreeNode<T>*> &retArr, TreeNode<T>* node){
    if(node == nullptr){return;}
    descendingrecursive(retArr, node->right);
    retArr.push_back(node);
    descendingrecursive(retArr, node->left);
    return;
}
template <typename T> void BinaryTree<T>::EmptyTreerecursive(TreeNode<T>* node){
    if(!node) return;
        EmptyTreerecursive(node->left);
        EmptyTreerecursive(node->right);
        delete node;
}