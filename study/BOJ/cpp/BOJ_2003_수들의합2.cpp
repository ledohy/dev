#include <iostream>

int arr[10005];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, ans = 0;
    
    std::cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    
    int en = 0;
    int sum = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && sum < m) {
            sum += arr[en++];
            if (sum == m)
                ans++;
        }
        sum -= arr[st];
        if (sum == m)
            ans++;
    }
    std::cout << ans << '\n';
    return 0;
}
