#include <iostream>
using namespace std;

int d[305];
int layer[305];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> layer[i];
        sum += layer[i];
    }
    d[1] = layer[1];
    d[2] = layer[2];
    d[3] = layer[3];
    for (int i = 4; i <= n-1; i++)
        d[i] = min(d[i-2], d[i-3]) + layer[i];
    cout << sum - min(d[n-1], d[n-2]) << '\n';
    return 0;
}