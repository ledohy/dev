#include <iostream>
#include <algorithm>
using namespace std;

int a[1005];
int d[1005];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    d[1] = a[1];
    for (int i = 2; i <= n; i++) {
        d[i] = a[i];
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i]) d[i] = max(d[i], d[j] + a[i]);
        }
    }
    cout << *max_element(d+1, d+1+n) << '\n';
}