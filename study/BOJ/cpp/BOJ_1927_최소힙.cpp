#include <iostream>

class node
{
    friend class heap;
private:
    int data;
public:
    node(int input = 0)
    :   data{ input } {}
    //int getData() { return data; }
};

class heap
{
private:
    node nd[200005];
    int size;
public:
    heap()
    :   size{ 0 } {}

    bool isEmpty() { return size == 0; }

    void insert(int input)
    {
        nd[++size] = input;
        int index = size;
        while (index != 1)
        {
            if (nd[index].data < nd[index / 2].data)
            {
                int temp = nd[index].data;
                nd[index] = nd[index/2].data;
                nd[index/2].data = temp;
            }
            index /= 2;
        }
    }
    int pop()
    {
        if (isEmpty()) return 0;
        int par = 1;
        int child = 2;

        int rtn_val = nd[1].data;
        nd[1].data = nd[size--].data;

        while (par < size)
        {
            if (nd[child].data > nd[child+1].data)
                child++;

            if (child > size)
                break;

            if (nd[par].data > nd[child].data)
            {
                int temp = nd[par].data;
                nd[par].data = nd[child].data;
                nd[child].data = temp;
            }

            par = child;
            child = par * 2;
        }
        return rtn_val;
    }
};

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    heap h;
    int n, input;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> input;

        if (input == 0)
            std::cout << h.pop() << '\n';

        else
            h.insert(input);
    }

    return 0;
}