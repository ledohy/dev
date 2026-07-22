#include <iostream>
#include <vector>
#include <queue>

std::vector<int> V[1002];
std::queue<int> q;
bool check[1002];

void BFS(int data) 
{
    q.pop();
    for (auto it : V[data])
    {
        if (check[it] == false)
        {
            q.push(it);
            check[it] = true;
            BFS(it);
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    int u, v;
    int count{0};
    
    std::cin >> n >> m;

    for (int i = 0 ; i < m; i++)
    {
        std::cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (check[i] == false)
        {
            q.push(i);
            check[i] = true;
            BFS(i);
            count++;
        }
    }

    std::cout << count << '\n';

    return 0;
}