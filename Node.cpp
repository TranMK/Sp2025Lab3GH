class Node{
    public:
        char data;
        Node *left, *right;
    Node(): data(0), left(nullptr), right(nullptr) {}
    Node(char data): data(data), left(nullptr), right(nullptr) {}
};