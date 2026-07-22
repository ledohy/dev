#include <iostream>

int arr[100005];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, s, sum = 0;
    int len = 0;
    int ans = 100001;

    std::cin >> n >> s;
    for (int i = 0 ; i < n; i++)
        std::cin >> arr[i];

    int en = 0;
    for (int st = 0; st < n; st++, len--) {
        while (en < n && sum < s) {
            sum += arr[en++];
            len++;
        }
        if (sum < s) break;
        sum -= arr[st];
        ans = std::min(ans, len);
        if (en == n) continue;
    }

    if (ans == 100001)
        std::cout << 0 << '\n';
    else
        std::cout << ans << '\n';
    return 0;
}