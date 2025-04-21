#include <algorithm>
#include <iostream>
#include <vector>
#include "TreeNode.hpp"
using namespace std;
template <typename T> class BinaryTree {
private:
    TreeNode<T>* root;
    int size = 0;
    TreeNode<T>* rightrotate(TreeNode<T>* node);
    TreeNode<T>* leftrotate(TreeNode<T>* node);
    TreeNode<T>* insertrecursive(TreeNode<T>* node, T value);
    TreeNode<T>* leftlargest(TreeNode<T>* node);
    TreeNode<T>* deleterecursive(TreeNode<T>* node, T value, TreeNode<T>*& removedNode);
    void inorder(TreeNode<T>* node);
    TreeNode<T>* findrecursive(TreeNode<T>* node, T value);
    void ascendingrecursive(vector<TreeNode<T>*> &retarr, TreeNode<T>* node);
    void descendingrecursive(vector<TreeNode<T>*> &retarr, TreeNode<T>* node);
    void EmptyTreerecursive(TreeNode<T>* node);
public:
    BinaryTree()
        : root(nullptr)
    {
    }
    ~BinaryTree(){EmptyTree();}
    int height(TreeNode<T>* node);
    int balancefactor(TreeNode<T>* node);
    void Insert(T value) {
        root = insertrecursive(root, value);
    }
    TreeNode<T>* Remove(T value) {
        TreeNode<T>* removedNode = nullptr;
        root = deleterecursive(root, value, removedNode);
        return removedNode; 
    }
    TreeNode<T>* Find(T value) {
        return findrecursive(root, value);
    }
    int getSize(){return size;}
    void printInorder()
    {
        inorder(root);
        cout << endl;
    }
    void EmptyTree(){
        EmptyTreerecursive(root);
        size = 0;
    }
    vector<TreeNode<T>*> GetAllAscending(){
        vector<TreeNode<T>*> retArr;
        ascendingrecursive(retArr, root);
        return retArr;
    }
    vector<TreeNode<T>*> GetAllDescending(){
        vector<TreeNode<T>*> retArr;
        descendingrecursive(retArr, root);
        return retArr;
    }
};
template class BinaryTree<int>;
template class BinaryTree<std::string>;
template class TreeNode<int>;
template class TreeNode<std::string>;