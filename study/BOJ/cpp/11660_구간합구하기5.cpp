//#include <iostream>
//using namespace std;
//
//int brd[1030][1030];
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= n; j++) {
//            cin >> brd[i][j];
//            brd[i][j] += brd[i][j-1];
//        }
//    while (m--) {
//        int x1, y1, x2, y2;
//        cin >> x1 >> y1 >> x2 >> y2;
//        int sum = 0;
//        for (int i = x1; i <= x2; i++)
//            sum += brd[i][y2] - brd[i][y1-1];
//        cout << sum << '\n';
//    }
//    return 0;
//}
