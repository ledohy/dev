//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//pair<int,int> t[100005];
//
//int main(void) {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    int n, ans = 0;
//    cin >> n;
//    for (int i = 0; i < n; i++) cin >> t[i].second >> t[i].first;
//    sort(t, t+n);
//    int cur = 0;
//    for (int i = 0; i < n; i++) {
//        if (cur > t[i].second) continue;
//        ans++;
//        cur = t[i].first;
//    }
//    cout << ans << '\n';
//}
