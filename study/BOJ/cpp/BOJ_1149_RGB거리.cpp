#include <iostream>
#include <algorithm>
using namespace std;

int r[1005];
int g[1005];
int b[1005];
int D[1005][3];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> r[i] >> g[i] >> b[i];

    D[0][0] = r[0];
    D[0][1] = g[0];
    D[0][2] = b[0];
    for (int i = 1; i < n; i++) {
        D[i][0] = min(D[i-1][1], D[i-1][2]) + r[i];
        D[i][1] = min(D[i-1][0], D[i-1][2]) + g[i];
        D[i][2] = min(D[i-1][0], D[i-1][1]) + b[i];
    }
    
    cout << *min_element(D[n-1], D[n-1] + 3) << '\n';
    return 0;
}