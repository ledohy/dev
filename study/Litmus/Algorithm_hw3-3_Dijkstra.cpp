#include <iostream>
#include <algorithm>
#include <queue>

std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> q;
bool visited[1005];
int list[1005][1005];
int dist[1005];
int prev[1005];

int Dijkstra(int, int, int);
int extractMin(int);

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    int x, y, z;
    int start, end;
    int shortest;
    
    std::cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j) list[i][j] = 0;
            else list[i][j] = -1;
    
    for (int i = 0; i < m; i++) {
        std::cin >> x >> y >> z;
        list[x][y] = z;
    }
    
    std::cin >> start >> end;
    
    shortest = Dijkstra(n, start, end);
    
    
    for (int i = 1; i <= n; i++)
        std::cout << prev[i] << ' ';
    
    if (shortest == 100000)
        std::cout << "Impossible\n";
    else
        std::cout << shortest << '\n';
    return 0;
}



inline int Dijkstra(int n, int start, int end)
{
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 100000;
        prev[i] = 0;
    }
    dist[start] = 0;
    
    while (1) {
        int u = extractMin(n);
        if (u == 0)
            break;
        
        visited[u] = true;
        for (int i = 1; i <= n; i++) {
            if (list[u][i] >= 0 && dist[i] > dist[u] + list[u][i]) {
                dist[i] = dist[u] + list[u][i];
                prev[i] = u;
            }
        }
    }
    return dist[end];
}

int extractMin(int n)
{
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false && dist[i] != 100000)
            q.push( {dist[i], i} );
    }
    
    if (q.empty())
        return 0;
    
    int min = q.top().second;
    while (!q.empty())
        q.pop();
    return min;
}
