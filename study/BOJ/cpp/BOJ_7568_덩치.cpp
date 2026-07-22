#include <iostream>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::pair<int,int> list[52];
    int rank[52];
    int n;
    
    std::cin >> n;
    std::fill(rank, rank + n, 1);
    for (int i = 0; i < n; i++)
        std::cin >> list[i].first >> list[i].second;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (list[i].first < list[j].first && list[i].second < list[j].second)
                rank[i]++;
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << rank[i] << ' ';
    std::cout << '\n';

    return 0;
}