#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> th;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, w, v;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        if (w > k) continue;
        th.push_back({w,v});
    }
    sort(th.begin(), th.end());
}