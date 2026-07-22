#include <iostream>

int list[1000005];

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num;
    std::cin >> num;

    list[1] = 0;
    for (int i = 2; i <= num; i++) {
        list[i] = list[i-1] + 1;
        if (i % 2 == 0) list[i] = std::min(list[i], list[i/2]+1);
        if (i % 3 == 0) list[i] = std::min(list[i], list[i/3]+1);
    }
    std::cout << list[num] << '\n';
    return 0;
}