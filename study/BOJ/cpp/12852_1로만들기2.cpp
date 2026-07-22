//#include <iostream>
//using namespace std;
//
//int D[1000005];
//int pre[1000005];
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    
//    int n;
//    cin >> n;
//    D[1] = 0;
//    for (int i = 2; i <= n; i++) {
//        D[i] = D[i-1] + 1;
//        pre[i] = i-1;
//        if (i%2 == 0 && D[i] > D[i/2] + 1) {
//            D[i] = D[i/2] + 1;
//            pre[i] = i/2;
//        }
//        if (i%3 == 0 && D[i] > D[i/3] + 1) {
//            D[i] = D[i/3] + 1;
//            pre[i] = i/3;
//        }
//    }
//    cout << D[n] << '\n';
//    
//    int cur = n;
//    while (1) {
//        cout << cur << ' ';
//        if (cur == 1) break;
//        cur = pre[cur];
//    }
//    return 0;
//}
