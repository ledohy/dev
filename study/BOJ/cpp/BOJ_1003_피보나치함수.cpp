#include <iostream>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    int num;
    std::pair<int, int> fib[42];

    fib[0] = { 1, 0 };
    fib[1] = { 0, 1 };
    for (int i = 2; i <= 40; i++)
    {
        fib[i].first = fib[i-1].first + fib[i-2].first;
        fib[i].second = fib[i-1].second + fib[i-2].second;
    }

    std::cin >> T;
    while (T--)
    {
        std::cin >> num;
        std::cout << fib[num].first << ' ' << fib[num].second << '\n';
    }

    return 0;
}