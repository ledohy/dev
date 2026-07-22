#include <iostream>

class node
{
private:
    int val;
    node* left;
    node* right;
public:
    node(int input)
    :   val{ input }, left{ nullptr }, right{ nullptr } {}

    int&   getVal()   { return val; }
    node*& getLeft()  { return left; }
    node*& getRight() { return right; }
};

class BST
{
private:
    node* root_p;
public:
    BST() 
    :   root_p{ nullptr } {}
    
    node*& getRoot() { return root_p; } 

    void insert(int val)
    {
        node* new_node = new node(val);
        if (root_p == nullptr) root_p = new_node;
        else 
        {
            find(root_p, val) = new_node;
            *find(root_p, val) = val;
        }
    }

    void del(int val)
    {
        node** nd;
        node* temp;
        node*& target = find(root_p, val);

        if (target->getLeft() == nullptr && target->getRight() == nullptr)
        {
            delete target;
            target = nullptr;
        }
        else if (target->getLeft() == nullptr || target->getRight() == nullptr)
        {
            nd = (target->getLeft() != nullptr) ? &target->getLeft() : &target->getRight();
            temp = target;
            target = (*nd); 
        }
        else
        {
            nd = &target->getRight();
            while (1) 
            {
                if ((*nd)->getLeft() == nullptr)
                {
                    temp = (*nd);
                    (*nd) = (*nd)->getRight();
                    break;
                }
                nd = &(*nd)->getLeft();
            }

            target->getVal() = temp->getVal();
            delete temp;
        }
        temp = nullptr;
    }


    node*& find(node*& th, const int val)
    {
        if (th->getVal() == val) return th;

        else if (th->getVal() > val) 
        {
            if (th->getLeft() == nullptr) return th->getLeft();
            else return find(th->getLeft(), val);
        }
        else
        {
            if (th->getRight() == nullptr) return th->getRight();
            else return find(th->getRight(), val);
        }
    }

    void preorder(node& th)
    {
        std::cout << th.getVal() << ' ';
        if (th.getLeft() != nullptr) preorder(*th.getLeft());
        if (th.getRight() != nullptr) preorder(*th.getRight());
    }
    void inorder(node& th)
    {
        if (th.getLeft() != nullptr) inorder(*th.getLeft());
        std::cout << th.getVal() << ' ';
        if (th.getRight() != nullptr) inorder(*th.getRight());
    }
    void postorder(node& th)
    {
        if (th.getLeft() != nullptr) postorder(*th.getLeft());
        if (th.getRight() != nullptr) postorder(*th.getRight());
        std::cout << th.getVal() << ' ';
    }
};

int main(void)
{
    int n, val;
    char order;
    std::cin >> n;


    BST tree;
    for (int i = 0; i < n; i++)
    {
        std::cin >> order >> val;
        if (order == 'I') 
            tree.insert(val);
        else
            tree.del(val);
    }

    std::cout << "preorder: ";
    tree.preorder(*tree.getRoot());
    std::cout << '\n';

    std::cout << "inorder: ";
    tree.inorder(*tree.getRoot());
    std::cout << '\n';

    std::cout << "postorder: ";
    tree.postorder(*tree.getRoot());
    std::cout << '\n';

    return 0;
}