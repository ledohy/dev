//#include <iostream>
//#include <queue>
//#define X first
//#define Y second
//using namespace std;
//
//queue<pair<pair<int,int>, int>> q;
//int brd[1005][1005];
//int dist[1005][1005][2];
//int dx[4] = { 0, 0, 1, -1 };
//int dy[4] = { 1, -1, 0, 0 };
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    char input;
//    int n, m;
//    cin >> n >> m;
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < m; j++) {
//            cin >> input;
//            brd[i][j] = input - '0';
//        }
//    q.push( {{0, 0}, 1} );
//    dist[0][0][0] = dist[0][0][1] = 1;
//    while (!q.empty()) {
//        auto cur = q.front(); q.pop();
//        for (int nt = 0; nt < 4; nt++) {
//            int nx = cur.X.X + dx[nt];
//            int ny = cur.X.Y + dy[nt];
//            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
//                continue;
//            if (cur.Y == 0 && brd[nx][ny] == 1)
//                continue;
//            if (brd[nx][ny] == 0) {
//                if (dist[nx][ny][cur.Y] == 0 || dist[cur.X.X][cur.X.Y][cur.Y] + 1 < dist[nx][ny][cur.Y]) {
//                    dist[nx][ny][cur.Y] = dist[cur.X.X][cur.X.Y][cur.Y] + 1;
//                    q.push({{nx, ny},cur.Y});
//                }
//            }
//            else if (brd[nx][ny] == 1) {
//                if (dist[nx][ny][0] == 0 || dist[cur.X.X][cur.X.Y][cur.Y] + 1 < dist[nx][ny][0]) {
//                    dist[nx][ny][0] = dist[cur.X.X][cur.X.Y][cur.Y] + 1;
//                    q.push({{nx, ny}, cur.Y-1});
//                }
//            }
//        }
//    }
//    if (dist[n-1][m-1][0] == 0 && dist[n-1][m-1][1] == 0)
//        cout << -1 << '\n';
//    else if (dist[n-1][m-1][0] * dist[n-1][m-1][1] == 0)
//        cout << max(dist[n-1][m-1][0], dist[n-1][m-1][1]) << '\n';
//    else
//        cout << min(dist[n-1][m-1][0], dist[n-1][m-1][1]) << '\n';
//    return 0;
//}
