#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M[11];
    int B, S;
    float L;
    int ans = 0;

    for (int i = 0; i < 11; i++)
        cin >> M[i];
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> B >> L >> S;
        if (L >= 2.0 && S >= 17)
            ans += M[B];
    }
    cout << ans << '\n';
    
    return 0;
}