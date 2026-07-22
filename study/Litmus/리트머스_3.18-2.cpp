#include <iostream>

int main(void)
{
    int n, max, min;
    int temp;

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> temp;
        if (i == 0)
        {
            max = temp;
            min = temp;
        }
        else
        {
            if (temp > max)
                max = temp;
            if (temp < min)
                min = temp;
        }
    }
    std::cout << max << ' ' << min << std::endl;

    return 0;
}