#include <iostream>
#include <vector>

std::vector<int> squares;

bool find_three(int goal);
bool find_two(int goal);

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int result = 4;

    std::cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        squares.push_back(i * i);
        if (i * i == n) {
            std::cout << 1 << '\n';
            return 0;
        }
    }

    if (find_three(n)) result = 3;
    if (find_two(n)) result = 2;

    std::cout << result << '\n';

    return 0;
}

bool find_three(int goal)
{
    for (auto i = squares.rbegin(); i != squares.rend(); i++)
    {
        for (auto j = i; j != squares.rend(); j++)
        {
            for (auto k = j; k != squares.rend(); k++)
            {
                if (*i + *j + *k == goal)
                    return true;
            }
        }
    }
    return false;
}
bool find_two(int goal)
{
    for (auto i = squares.rbegin(); i != squares.rend(); i++)
    {
        for (auto j = i; j != squares.rend(); j++)
        {
            if (*i + *j == goal)
                return true;
        }
    }
    return false;
}