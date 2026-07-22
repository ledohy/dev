#include <iostream>
#include <queue>


struct cmp {
    bool operator() (int& a, int& b)
    {
        int a_val = a;
        int b_val = b;
        if (a_val < 0)
            a_val = -a_val;
        if (b_val < 0)
            b_val = -b_val;

        if (a_val == b_val)
            return a >= b;
        
        else
            return a_val >= b_val;
    }
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<int, std::vector<int>, cmp> pq;
    int n, input;

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        if (input == 0)
        {
            if (pq.empty())
                std::cout << 0 << '\n';

            else {
                std::cout << pq.top() << '\n';
                pq.pop();
            }
        }

        else 
            pq.push(input);
    }

    return 0;
}