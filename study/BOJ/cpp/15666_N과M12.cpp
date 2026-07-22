//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <set>
//using namespace std;
//
//set<vector<int>> ans;
//vector<int> v;
//int list[10];
//int n, m;
//
//void bT(int count) {
//    if (count >= m) {
//        ans.insert(v);
//        return;
//    }
//    for (int i = 0; i < n; i++) {
//        if (!v.empty())
//            if (list[i] < v.back()) continue;
//        v.push_back(list[i]);
//        bT(count+1);
//        v.pop_back();
//    }
//}
//
//int main(void) {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    
//    cin >> n >> m;
//    for (int i = 0; i < n; i++) cin >> list[i];
//    sort(list, list + n);
//    bT(0);
//    for (auto it : ans) {
//        for (auto it_v : it) cout << it_v << ' ';
//        cout << '\n';
//    }
//    return 0;
//}
