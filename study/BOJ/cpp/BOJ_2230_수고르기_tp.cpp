#include <iostream>
#include <algorithm>

int arr[100005];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    std::sort(arr, arr+n);

    int ans = arr[n-1] * 2;
    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && arr[en] - arr[st] < m) en++;
        if (en == n) break;
        ans = std::min(ans, arr[en] - arr[st]);
    }

    std::cout << ans << '\n';

    return 0;
}