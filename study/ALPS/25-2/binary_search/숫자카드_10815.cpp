#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v1, v2;
    int n, m, input;
    
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        v1.push_back(input);
    }

    std::cin >> m;
    for (int i = 0; i < m; i++) {
        std::cin >> input;
        v2.push_back(input);
    }

    std::sort(v1.begin(), v1.end());

    for (auto it : v2) {
        std::cout << std::binary_search(v1.begin(), v1.end(), it) << ' ';
    }
    std::cout << '\n';

    return 0;
}