#include <iostream>
#include <algorithm>
#define ll long long

ll arr[100005];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    ll result, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++) 
        std::cin >> arr[i];

    std::sort(arr, arr+n);

    result = arr[n-1] * 2;
    for (int i = 0; i < n; i++) {
        int p = i, r = n-1;
        ll diff;
        while (p <= r) {
            int q = (p + r) / 2;
            diff = arr[q] - arr[i];

            if (diff < m)
                p = q + 1;
            else 
            {
                if (diff < result)
                    result = diff;
                r = q - 1;
            }
        }
    }

    std::cout << result << '\n';
    return 0;
}