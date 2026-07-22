#include <iostream>

int main()
{
    int n = 1, result;

    while (1)
    {
        std::cin >> n;
        if (n == -1)
            return 0;
        else
        {
            result = 0;
            for (int i = 1; i < n; i++)
            {
                if (n % i == 0)
                    result += i;
            }
            if (n != result)
            {
                std::cout << n << " is NOT perfect." << '\n';
            }
            else
            {
                std::cout << n << " = " << 1;
                for (int i = 2; i < n; i++)
                {
                   if (n % i == 0)
                    std::cout << " + " << i;
                }
                std::cout << '\n';
            }
        }
    }
}
