#include <iostream>
#include <climits>
#include <queue>
#define INF INT_MAX
using namespace std;

queue<int> q;
int sp[100005];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= 100000; i++) sp[i] = INF;
    sp[n] = 0;
    q.push(n);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur < 100000 && sp[cur + 1] > sp[cur] + 1) {
            sp[cur+1] = sp[cur] + 1;
            q.push(cur+1);
        }
        if (cur > 0 && sp[cur - 1] > sp[cur] + 1) { 
            sp[cur - 1] = sp[cur] + 1;
            q.push(cur-1);
        }
        if (cur * 2 <= 100000 && sp[cur*2] > sp[cur]) {
            sp[cur*2] = sp[cur];
            q.push(cur*2);
        }
    }
    cout << sp[m] << '\n';
}