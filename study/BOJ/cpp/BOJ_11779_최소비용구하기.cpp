#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
const int INF = INT_MAX;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
vector<pair<int,int>> v[1005];
vector<int> d(1005, INF);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    int st, en, wt;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> st >> en >> wt;
        v[st].push_back({wt, en});
    }
    cin >> st >> en;
    d[st] = 0;
}