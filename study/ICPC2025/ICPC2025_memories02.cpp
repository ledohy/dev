#include <iostream>

int main()
{
    int n = 5, result = 0;
    while(true)
    {
        result = 0;
        std::cin >> n;
        if (n == -1)
        {
            return 0;
        }
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                result += i;
            }
        }
        if (result != n)
        {
            std::cout << n << " is NOT perfect." << '\n';
        }
        else
        {
            std::cout << n << " = 1";
            for (int i = 2; i <= n; i++)
            {
                if (n % i == 0)
                {
                    std::cout << " + " << n;
                }
            }
            std::cout << '\n';
        }
    }

    return 0;
}