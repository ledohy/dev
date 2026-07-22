#include <iostream>
#include <algorithm>
#include <vector>

bool tmp[4000005];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> arr;
    int ans = 0;
    int n;

    std::cin >> n;

    for (int i = 2; i <= n/2 + 1; i++) {
        int idx = 2;
        while (i * idx <= n) 
            tmp[i * idx++] = true;
    }

    for (int i = 2; i <= n; i++) 
        if (tmp[i] == false)
            arr.push_back(i);

    int en = 0;
    int sum = 0;
    int len = arr.size();
    for (int st = 0; st < len; st++) {
        while (en < len && sum < n) {
            sum += arr[en++];
            if (sum == n) {
                ans++;
                break;
            }
        }
        sum -= arr[st];
        if (sum == n)
            ans++;
    }

    std::cout << ans << '\n';
    return 0;
}