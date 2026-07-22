//#include <iostream>
//using namespace std;
//
//int stk[100005][3];
//int d[100005][3];
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int t, n;
//    cin >> t;
//    while (t--) {
//        cin >> n;
//        for (int i = 1; i <= 2; i++)
//            for (int j = 1; j <= n; j++)
//                cin >> stk[j][i];
//        d[1][1] = stk[1][1]; d[1][2] = stk[1][2];
//        d[2][1] = stk[2][1] + d[1][2];
//        d[2][2] = stk[2][2] + d[1][1];
//        for (int i = 1; i <= n; i++) {
//            d[i][1] = max(d[i-1][2], d[i-2][2]) + stk[i][1];
//            d[i][2] = max(d[i-1][1], d[i-2][1]) + stk[i][2];
//        }
//        cout << max(d[n][1], d[n][2]) << '\n';
//    }
//    return 0;
//}
