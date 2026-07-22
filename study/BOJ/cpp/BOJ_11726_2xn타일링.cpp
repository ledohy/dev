#include <iostream>
using namespace std;

int d[1005];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    d[1] = 1; d[2] = 2;
    for (int i = 3; i <= n; i++) d[i] = (d[i-1] + d[i-2]) % 10007;
    cout << d[n] << '\n';
    return 0;
}