#include <iostream>
#include <queue>

std::queue<int> fq, sq;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;

    std::cin >> n >> k;
    for (int i = 1; i <= n; i++)
        fq.push(i);

    int count{0};
    while (!fq.empty())
    {
        count++;
        if (count % k == 0)
            sq.push(fq.front());
        else
            fq.push(fq.front());

        fq.pop();
    }
    std::cout << '<';
    while (!sq.empty()){
        std::cout << sq.front();
        sq.pop();
        if (!sq.empty())
            std::cout << ", ";
    }
    std::cout << '>';
    std::cout << '\n';

    return 0;
}