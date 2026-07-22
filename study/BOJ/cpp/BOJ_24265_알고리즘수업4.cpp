#include <iostream>

int main(void)
{
    int n;
    unsigned long long sum{0};
    std::cin >> n;

    for (int i = 1; i < n; i++)
    {
        sum += i;
    }

    std::cout << sum << '\n';
    std::cout << 2 << '\n';

    return 0;
}