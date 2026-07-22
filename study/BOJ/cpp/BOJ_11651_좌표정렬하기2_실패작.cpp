#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::pair<int, int> pos[100000], temp;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> pos[i].first >> pos[i].second;
    }
    for (int i = 0 ; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (pos[j].second > pos[j + 1].second)
            {
                temp.first = pos[j].first;
                temp.second = pos[j].second;
                pos[j].first = pos[j + 1].first;
                pos[j].second = pos[j + 1].second;
                pos[j + 1].first = temp.first;
                pos[j + 1].second = temp.second;
            }
            if (pos[j].second == pos[j + 1].second && pos[j].first > pos[j + 1].first)
            {
                temp.first = pos[j].first;
                temp.second = pos[j].second;
                pos[j].first = pos[j + 1].first;
                pos[j].second = pos[j + 1].second;
                pos[j + 1].first = temp.first;
                pos[j + 1].second = temp.second;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << pos[i].first << ' ' << pos[i].second << '\n';
    }
    return 0;
}