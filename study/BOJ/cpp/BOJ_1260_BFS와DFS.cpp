#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

std::vector<int> v[1002];
std::queue<int> q;
bool visited[1002];

void DFS(int node)
{
    visited[node] = true;
    std::cout << node << ' ';
    for (int it : v[node])
    {
        if (!visited[it])
            DFS(it);
    }
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, start;
    int input1, input2;

    std::cin >> n >> m >> start;
    for (int i = 0; i < m; i++)
    {
        std::cin >> input1 >> input2;
        v[input1].push_back(input2);
        v[input2].push_back(input1);
    }

    for (int i = 0; i <= n; i++)
        std::sort(v[i].begin(), v[i].end());

    DFS(start);
    std::cout << '\n';

    std::memset(visited, false, sizeof(visited));

    q.push(start);
    while (!q.empty())
    {
        int node = q.front(); q.pop();
        std::cout << node << ' ';
        visited[node] = true;
        for (int it : v[node])
        {
            if (!visited[it])
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
    std::cout << '\n';
    
    return 0;
}