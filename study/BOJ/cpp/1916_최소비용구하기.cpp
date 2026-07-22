//#include <iostream>
//#include <queue>
//#define uint unsigned int
//using namespace std;
//
//uint city[1005][1005];
//queue<uint> q;
//uint dist[1005];
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    uint n, m;
//    uint x, y, z;
//    uint start, end;
//    cin >> n >> m;
//    
//    for (int i = 1; i <= n; i++) {
//        fill(city[i]+1, city[i] + n+1, -1);
//    }
//    for (int i = 1; i <= m; i++) {
//        cin >> x >> y >> z;
//        city[x][y] = z;
//    }
//    cin >> start >> end;
//    dist[start] = 0;
//    q.push(start);
//    while (!q.empty()) {
//        uint cur = q.front(); q.pop();
//        for (uint it : city[cur]) {
//            if (city[cur][it] == -1 || dist[it] > dist[cur] + city[cur][it])
//                dist[it] = dist[cur] + city[cur][it];
//            else q.push(it);
//        }
//    }
//    cout << dist[end] << '\n';
//    return 0;
//}
