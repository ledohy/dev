#include <iostream>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str[3];
    int target, result;

    for (int i = 0; i < 3; i++)
    {
        std::cin >> str[i];
        if (0 < str[i][0] && str[i][0] <= '9')
            target = i;
    }

    result = std::stoi(str[target]) + 3-target;

    if (result % 3 == 0 || result % 5 == 0)
    {
        if (result % 3 == 0)
            std::cout << "Fizz";
        if (result % 5 == 0)
            std::cout << "Buzz";
        std::cout << '\n';
    }
    else
        std::cout << result << '\n';

    return 0;
}