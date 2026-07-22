#include <iostream>
#include <unordered_set>
#include <map>
#include <queue>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::unordered_multiset<int> ms;
    std::map<int,int> dic;
    std::queue<int> q;
    int n, m, input;
    
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        ms.insert(input);
    }

    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        std::cin >> input;
        q.push(input);
    }

    while (!q.empty())
    {
        int target = q.front(); q.pop();

        if (dic.find(target) == dic.end())
            dic[target] = ms.count(target);

        std::cout << dic[target] << ' ';
    }
    std::cout << '\n';

    return 0;
}