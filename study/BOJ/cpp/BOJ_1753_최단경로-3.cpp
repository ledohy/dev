#include <iostream>
#include <vector>
#include <queue>
#define INF 200005
#define X first
#define Y second

std::priority_queue<std::pair<int, int>> q;
std::vector<std::pair<int, int>> vt[20005];
int dist[20005];

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int V, E;
    int start;
    int u, v, w;

    std::cin >> V >> E >> start;
    while (E--)
    {
        std::cin >> u >> v >> w;
        vt[u].push_back({v,w});
    }
    for (int i = 1; i <= V; i++)
        dist[i] = INF;

    q.push({0,start});
    dist[start] = 0;

    while (!q.empty())
    {
        int cost = -q.top().X;
        int local = q.top().Y; q.pop();
        int size = vt[local].size();

        for (int i = 0; i < size; i++)
        {
            int nxt = vt[local][i].X;
            int Lcost = vt[local][i].Y;

            if (dist[nxt] > cost + Lcost) {
                dist[nxt] = cost + Lcost;
                q.push({-dist[nxt],nxt});
            }
        }
    }

    for (int i = 1; i <= V; i++)
    {
        if (dist[i] == INF)
            std::cout << "INF" << '\n';
        else
            std::cout << dist[i] << '\n';
    }

    return 0;
}