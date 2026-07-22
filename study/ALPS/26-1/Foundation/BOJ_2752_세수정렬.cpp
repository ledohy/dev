#include <iostream>
#include <algorithm>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num[3];
    std::cin >> num[0] >> num[1] >> num[2];
    std::sort(num, num+3);
    std::cout << num[0] << ' ' << num[1] << ' ' << num[2] << '\n';
    return 0;
}