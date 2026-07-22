#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

char board[102][102];
int dist[102][102];
queue<pair<pair<int,int>,int>> q;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    q.push( { {0,0}, 1 } );

    while (!q.empty()) {
        pair<pair<int,int>,int> cur = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X.X + dx[dir];
            int ny = cur.X.Y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            
            if (board[nx][ny] == '0')
                continue;

            if (dist[nx][ny] != 0 && dist[nx][ny] <= dist[cur.X.X][cur.X.Y] + 1)
                continue;

            dist[nx][ny] = cur.Y + 1;
            q.push( { { nx, ny }, dist[nx][ny] });
        }
    }

    cout << dist[n-1][m-1] << '\n';

    return 0;
}