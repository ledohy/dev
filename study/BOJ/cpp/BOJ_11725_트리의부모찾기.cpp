#include <iostream>
#include <vector>

std::vector<int> v[100005];
int parent[100005];

void findChild(int par)
{
    for (int it : v[par])
    {
        if (parent[par] == it)
            continue;
        parent[it] = par;
        findChild(it);
    }
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int first, second;
    std::cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> first >> second;
        v[first].push_back(second);
        v[second].push_back(first);
    }
    findChild(1);

    for (int i = 2; i <= n; i++)
        std::cout << parent[i] << '\n';

    return 0;
}