#include <iostream>
#include <algorithm>
#include <queue>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> q;

    int city[1005][1005];
    int dist[1005];
    for (int i = 1; i < 1001; i++) {
        std::fill(city[i] + 1, city[i] + 1001, -1);
        dist[i] = -1;
    }

    int n, m, start, end;
    int a, b, cost;
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b >> cost;
        city[a][b] = cost;
    }
    std::cin >> start >> end;

    q.push( { 0, start } );
    while (!q.empty()) {
        std::pair<int,int> cur = q.top(); q.pop();
        for (int i = 1; i <= n; i++) {
            if (city[cur.second][i] == -1) continue;
            if (i == start || i == cur.second) continue;
            if (city[start][i] != -1 && city[start][i] <= city[cur.second][i] + cur.first) continue;

            city[start][i] = cur.first + city[cur.second][i];
            q.push( { city[start][i], i } );
        }
    }
    std::cout << city[start][end] << '\n';
    return 0;
}