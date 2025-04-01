#include "Node.cpp"
class Tree{
    protected:
        Node *root;
        Tree(): root(nullptr) {}
        Tree(char inVal){
            root = new Node(inVal);
        }
        void Insert(char inVal);
        char Find(char target){};
        void PrintSub(Node *place){};
        void Print(){};
        void PrintS(Node *place){};
        char Remove(char Inval){};
        char LeftLargest(Node* parent){};
        void RotateLeft(Node *parent, Node *child){};
        void RotateRight(Node *parent, Node *child){};
        void RotateRL(Node* parent, Node* child){};
        void RotateLR(Node* parent, Node* child){};
        int Levels(Node *parent, Node *child){};
};
