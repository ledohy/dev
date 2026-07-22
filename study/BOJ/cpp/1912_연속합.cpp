//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int a[100005];
//int d[100005];
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    int n;
//    cin >> n;
//    for (int i = 1; i <= n; i++) cin >> a[i];
//    for (int i = 1; i <= n; i++) {
//        if (d[i-1] <= 0 || d[i-1] < -a[i]) d[i] = a[i];
//        else d[i] = d[i-1] + a[i];
//    }
//    cout << *max_element(d+1, d+1+n) << '\n';
//    return 0;
//}
