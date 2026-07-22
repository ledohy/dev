#include <iostream>

int main()
{
    int tc, result = 0, input;

    std::cin >> tc;
    while(tc--) 
    {
        std::cin >> input;
        for (int i = 2; i <= input; i++)
        {
            if (i == input)
                result++;

            if (input % i == 0)
                break;
        }
    }
    std::cout << result << '\n';
    
    {

    }

    return 0;
}