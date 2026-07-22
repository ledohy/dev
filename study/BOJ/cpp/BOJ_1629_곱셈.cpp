#include <iostream>
#define ull unsigned long long
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ull a, b, c, ans = 1;
    cin >> a >> b >> c;
    ull supos = 1;
    int cnt = 0;
    for (int i = 0; i < 10000; i++) {
        supos *= a % c;
        supos %= c;
        cnt++;
        if (cnt >= b) break;
    }
    for (int i = 0; i < b/cnt; i++) {
        ans *= supos % c;
        ans %= c;
    }
    for (int i = 0; i < b%cnt; i++) {
        ans *= a % c;
        ans %= c;
    }
    cout << ans << '\n';
    return 0;
}
