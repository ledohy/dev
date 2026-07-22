#include <iostream>
#include <vector>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> s;
    int n, k, input;
    int len = 0, max = 0;
    int odd_count = 0;

    std::cin >> n >> k;

    for (int i = 0; i < n; i++) {
        std::cin >> input;
        s.push_back(input);
    }

    int en = 0;
    for (int st = 0; st < n; st++) {
        while (en < n && odd_count <= k) 
        {
            if (s[en++] % 2 == 0) 
                max = std::max(++len, max);
            else
                odd_count++;
        }
        if (s[st] % 2 == 0) 
            len--;
        else
            odd_count--;
    }
    std::cout << max << '\n';
    return 0;
}