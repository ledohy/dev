#include <iostream>

int main(void)
{
    int paper[102][102] = { 0, };
    int n;
    int total = 0;
    int x, y;

    std::cin >> n;
    while (n--)
    {
        std::cin >> x >> y;
        for (int i = x; i < x + 10; i++)
        {
            for (int j = y; j < y + 10; j++)
            {
                paper[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (paper[i][j] == 1)
                total++;
        }
    }

    std::cout << total << std::endl;

    return 0;
}