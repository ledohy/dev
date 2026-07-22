#include <iostream>

int main(void)
{
    int up, down, day, total, result = 0;

    std::cin >> up >> down >> total;
    total -= up;
    day = up - down;

    result = total / day;

    if (total % day != 0)
        result++;

    std::cout << result + 1 << '\n';
    return 0;
}