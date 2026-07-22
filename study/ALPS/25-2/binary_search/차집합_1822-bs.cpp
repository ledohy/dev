#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v1, v2, result;
    int a, b, input;

    std::cin >> a >> b;

    for (int i = 0; i < a; i++) {
        std::cin >> input;
        v1.push_back(input);
    }
    for (int i = 0; i < b; i++) {
        std::cin >> input;
        v2.push_back(input);
    }

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    for (auto it : v1) {
        if (std::binary_search(v2.begin(), v2.end(), it)) 
            continue;
        else
            result.push_back(it);
    }

    std::cout << result.size() << '\n';

    for (auto it : result) 
    {
        std::cout << it << ' ';
    }

    return 0;
}