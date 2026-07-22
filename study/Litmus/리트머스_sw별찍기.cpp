#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int line = 1;
    for (int i = 0; i < n; i++) line *= 2;
    for (int i = 1; i < line; i++) {
        if (i % 2 == 1) cout << "*\n";
        else {
            int cnt = 0;
            int p = 1, r = line-1;
            int q = (p+r)/2;
            while (i != q) {
                cnt++;
                if (i < q) r = q-1;
                else p = q+1;
                q = (p+r)/2;
            }
            for (int j = 0; j < n - cnt; j++) cout << '*';
            cout << '\n';
        }
    }
}