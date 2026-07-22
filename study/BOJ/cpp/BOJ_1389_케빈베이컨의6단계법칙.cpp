#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;



vector<int> v[101];
queue< pair<int,int> > q;
priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
bool check[101];

int BFS(int idx, int to)
{
    q.push( {idx, 1} );

    while (!q.empty()) {
        pair<int,int> p = q.front(); q.pop();

        for (auto it : v[p.X]) {
            if (it == to)
                return p.Y;
            else if (check[it] == true) 
                continue;
            else {
                check[it] = true;
                q.push( {it, p.Y +1} );
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    int u, w;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> w;
        v[u].push_back(w);
        v[w].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        int temp{0};

        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            
            while (!q.empty()) q.pop();

            fill(check, check + n+1, false);
            check[i] = true;
            temp += BFS(i, j);
        }
        pq.push( {temp, i} );

    }

    cout << pq.top().Y << '\n';

    return 0;
}