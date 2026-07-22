#include <iostream>
int count;

class node
{
    friend class tree;
private:
    node* child[50];

public:
    node() 
    {
        for (int i = 0; i < 50; i++)
            child[i] = nullptr;
    }
};

class tree
{
private:
    node* root;
    node nd[50];
    int size;
public:
    tree()
    : size{ 0 } {}
    void pointChild(int par)
    {
        if (par == -1)          //부모가 -1이면 
            root = &nd[size];   //네가 루트야
        
        else       
            nd[par].child[size] = &nd[size];    
        
        size++;
    }
    void cutting(int cut)   //cut을 인덱스로 갖는 노드의 child를 전부 끊어줌
    {
        if (&nd[cut] == root)   //루트를 컷해야할 경우
        {
            for (int i = 0; i < size; i++)
            {
                root->child[i] = nullptr;
            }
            count--;        //child뿐만 아니라 본인도 cut당함
            return;
        }

        for (int i = 0; i < size; i++)
        {
            if (nd[i].child[cut] != nullptr)
                nd[i].child[cut] = nullptr;
        }
    }

    int countLeaf()
    {
        recur(*root);
        return count;
    }

    void recur(node& nod)
    {
        bool flag = true;                   //리프노드인지 아닌지 판단해줄 플래그
        for (int i = 0; i < 50; i++)
        {
            if (nod.child[i] != nullptr)    //하나라도 nullptr 아닌 노드가 발견됐다면
            {
                flag = false;               //얘는 리프노드가 아니고
                recur(nd[i]);               //얘의 자식노드들로 재귀함수
            }
        }
        if (flag == true)                   //for문 속 if가 작동 안됐다면 플래그가 true이니
            count++;                        //리프노트 카운트++
        return;
    }
};

int main(void)
{
    std::ios_base::sync_with_stdio(false);      //이 두 줄은 속도를 높여줌
    std::cin.tie(nullptr);                      //외워두면 좋긴한데 필수는 X

    int n, input, cut;

    std::cin >> n;
    tree tr;

    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        tr.pointChild(input);
    }
    std::cin >> cut;
    tr.cutting(cut);

    std::cout << tr.countLeaf() << '\n';

    return 0;
}
