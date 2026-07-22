#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;

int board[1002][1002];
bool visited[1002][1002];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    queue<pair<int,int>> q;
    int w, h;
    
    std::cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                q.push( {i, j} );
                visited[i][j] = true;
                board[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        pair<int,int> p = q.front(); q.pop();

        for (int idx = 0; idx < 4; idx++) {
            int nx = p.X + dx[idx];
            int ny = p.Y + dy[idx];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (board[nx][ny] == 0 || visited[nx][ny])
                continue;
            
            board[nx][ny] = board[p.X][p.Y] + 1;
            visited[nx][ny] = true;
            q.push( {nx, ny} );
        }
    }

    for (int i = 0; i < h; i++) { 
        for (int j = 0; j < w; j++) {
            if (board[i][j] == 1 && !visited[i][j])
                cout << -1 << ' ';
            else
                cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}