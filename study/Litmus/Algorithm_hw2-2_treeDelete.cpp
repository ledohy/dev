//#include <iostream>
//
//class Node {
//    int key;
//    Node* left;
//    Node* right;
//public:
//    Node(int val) : key{ val }, left{ nullptr }, right{ nullptr } {}
//    
//    Node*& getLeft() { return left; }
//    Node*& getRight() { return right; }
//    int getKey() { return key; }
//    int& setKey() { return key; }
//};
//
//
//class BinarySearchTree {
//    Node* root;
//public:
//    BinarySearchTree() : root{ nullptr } {}
//    
//    
//    void Insert(int val) {
//        Node* nd = new Node(val);
//        search(val) = nd;
//    }
//    
//    
//    void Delete(int val) {
//        Node*& target = search(val);
//        Node* temp = target;
//        
//        if (target->getLeft() == nullptr && target->getRight() == nullptr) {
//            delete temp;
//            target = nullptr;
//        }
//        
//        else if (target->getLeft() != nullptr && target->getRight() != nullptr) {
//            if (target->getRight()->getLeft() == nullptr && target->getRight()->getRight() == nullptr) {
//                target->setKey() = target->getRight()->getKey();
//                delete target->getRight();
//                target->getRight() = nullptr;
//                return;
//            }
//            if ( temp->getRight()->getLeft() != nullptr) {
//                temp = temp->getRight();
//            }
//            else if (temp->getRight()->getRight() != nullptr) {
//                target->getRight() = temp->getRight()->getRight();
//                target->setKey() = temp->getRight()->getKey();
//                delete temp->getRight();
//                return;
//            }
//
//                
//
//            while (temp->getLeft() != nullptr) {
//                if (temp->getLeft()->getLeft() == nullptr) 
//                    break;
//                temp = temp->getLeft();
//            }
//
//            
//            target->setKey() = temp->getLeft()->getKey();
//            
//            Node* temp_del = temp->getLeft();
//            Node& ref = *temp;
//
//            ref.getLeft() = temp_del->getRight();
//            
//            delete temp_del;
//        }
//        
//        else {
//            target = (temp->getLeft() != nullptr) ? temp->getLeft() : temp->getRight();
//            delete temp;
//        }
//        
//    }
//
//    
//    Node*& search(int val) {
//        Node** target = &root;
//        while (1) {
//            if ( *target == nullptr ) break;
//            
//            if ( (*target)->getKey() == val ) break;
//            
//            target = ( val < (*target)->getKey() ) ? &((*target)->getLeft()) : &((*target)->getRight());
//        }
//        
//        return *target;
//    }
//    
//    
//    void Tour(int order) {
//        switch(order) {
//            case 0:
//                pre(root);
//                break;
//            case 1:
//                in(root);
//                break;
//            case 2:
//                post(root);
//                break;
//        }
//    }
//    
//    void pre(Node* par) {
//        if (par == nullptr) return;
//        
//        std::cout << par->getKey() << ' ';
//        pre( par->getLeft() );
//        pre( par->getRight() );
//    }
//    void in(Node* par) {
//        if (par == nullptr) return;
//        
//        in( par->getLeft() );
//        std::cout << par->getKey() << ' ';
//        in( par->getRight() );
//    }
//    void post(Node* par) {
//        if (par == nullptr) return;
//        
//        post( par->getLeft() );
//        post( par->getRight() );
//        std::cout << par->getKey() << ' ';
//    }
//};
//
//
//int main(void) {
//    BinarySearchTree bst;
//    int n, k;
//    int order, input;
//    
//    std::cin >> n;
//    while (n--) {
//        std::cin >> input;
//        bst.Insert(input);
//    }
//    
//    std::cin >> k;
//    while (k--) {
//        std::cin >> order >> input;
//        bst.Delete(input);
//        bst.Tour(order);
//        std::cout << '\n';
//    }
//    
//    return 0;
//}
