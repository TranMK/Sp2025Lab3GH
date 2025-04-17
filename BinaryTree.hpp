#include <string>
#include <vector>
template <typename T> class TreeNode{
    public:
    T value;
    int count;
    int balfac;
    int height;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){left,right = nullptr;}
    T getValue(){return value;}
    void incCount(){count++;}
    int getCount(){return count;}
};

template <typename T> class BinaryTree{
    private:
    TreeNode* root;
    int size;
    int getSize(){return size;}
    void insertpriv(TreeNode<T> *&nodePtr, TreeNode<T> *&newNode);
    void removeSubtree(TreeNode<T> *node);
    void deleteNode(int num, TreeNode<T> *node);
    void makeDeletion(TreeNode<T>* node);
    void update(TreeNode<T> *node);
    TreeNode<T>* balance(TreeNode<T>* node);
    TreeNode<T>* rotateLL(TreeNode<T>* node){
        return rightRotate(node);
    }
    TreeNode<T>* rotateLR(TreeNode<T>* node){
        node->left = leftRotate(node->left);
        return rotateLL(node);
    }
    TreeNode<T>* rotateRR(TreeNode<T>* node){
        return leftRotate(node);
    }
    TreeNode<T>* rotateRL(TreeNode<T>* node){
        node->right = rightRotate(node->right);
        return rightRotate(node);
    }
    TreeNode<T>* leftRotate(TreeNode<T>* node);
    TreeNode<T>* rightRotate(TreeNode<T>* node);
    bool findSub(TreeNode<T>* node, T inVal);
    TreeNode<T>* removeSubnode(TreeNode<T>* node, T inVal, TreeNode<T>*& removedNode);
    TreeNode<T>* leftLargest(TreeNode<T>* node);
    TreeNode<T>* rightSmallest(TreeNode<T>* node);
    // void displayInOrder(TreeNode* node)const;
    void GetAllAscendingRecursive(TreeNode<T>* node, std::vector< TreeNode<T>* > &NodeArr);
    void GetAllDescendingRecursive(TreeNode<T>* node, std::vector< TreeNode<T>* > &NodeArr);

    public:
    BinaryTree(){root = nullptr;}
    ~BinaryTree(){removeSubtree(root);}
    void Insert(T inVal);
    bool Find(T inVal);
    TreeNode<T>* Remove(T inVal);
    std::vector<T> GetAllAscending();
    std::vector<T> GetAllDescending();
    void EmptyTree();
    // void displayInOrder() const {displayInOrder(root);}
    // void displayPreOrder() const {displayPreOrder(root);}
    // void displayPostOrder() const {displayPostOrder(root);}
};