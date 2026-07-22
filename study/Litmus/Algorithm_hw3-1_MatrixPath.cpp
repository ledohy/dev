//#include <iostream>
//
//int dist[102][102];
//
//int Path(int n, int m)
//{
//    if (n == 1 && m == 1) return dist[1][1];
//    if (n-1 == 0) return Path(n, m-1) + dist[n][m];
//    if (m-1 == 0) return Path(n-1, m) + dist[n][m];
//    return std::min(Path(n-1, m), Path(n, m-1)) + dist[n][m];
//}
//
//int main(void) {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    
//    int n, m;
//    
//    std::cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            std::cin >> dist[i][j];
//    
//    std::cout << Path(n,m) << '\n';
//    return 0;
//}
