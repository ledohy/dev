//#include <iostream>
//
//class Node {
//private:
//    int key;
//    Node* left;
//    Node* right;
//public:
//    Node(int val) : key{ val }, left{ nullptr }, right{ nullptr } {}
//    
//    Node*& getLeft() { return left; }
//    Node*& getRight() { return right; }
//    int getKey() { return key; }
//};
//
//class binarySearchTree {
//private:
//    Node* root;
//    int count;
//public:
//    binarySearchTree() : root{ nullptr }, count{ 0 } {}
//    
//    Node* treeInsert(Node*& nd, int val) {
//        count++;
//        
//        if (nd == nullptr) {
//            nd = new Node(val);
//            return root;
//        }
//        
//        Node*& target = (val < nd->getKey()) ? nd->getLeft() : nd->getRight();
//        
//        return treeInsert(target, val);
//    }
//    
//    
//    Node* getRoot() { return root; }
//    int getCount() { return count; }
//};
//
//int main(void) {
//    binarySearchTree bst;
//    Node* root = bst.getRoot();
//    int n, input;
//    
//    
//    std::cin >> n;
//    for (int i = 0; i < n; i++) {
//        std::cin >> input;
//        bst.treeInsert(root, input);
//    }
//    
//    std::cout << bst.getCount() << '\n';
//    
//    return 0;
//}
