//#include <iostream>
//using namespace std;
//
//int d[505][505];
//int tri[505][505];
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        tri[i][0] = tri[i][i+1] = -1;
//        for (int j = 1; j <= i; j++) cin >> tri[i][j];
//    }
//    d[1][1] = tri[1][1];
//    for (int i = 2; i <= n; i++) {
//        for (int j = 1; j <= i; j++) d[i][j] = max(d[i-1][j-1], d[i-1][j]) + tri[i][j];
//    }
//    int Max = d[n][1];
//    for (int i = 2; i <= n; i++)
//        Max = max(Max, d[n][i]);
//    cout << Max << '\n';
//    return 0;
//}
