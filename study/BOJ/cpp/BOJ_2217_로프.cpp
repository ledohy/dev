#include <iostream>
#include <algorithm>
using namespace std;

int rp[100005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> rp[i];
    sort(rp, rp+n);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, rp[n-i]*i);
    cout << ans << '\n';
    return 0;
}