#include <iostream>

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    std::cin >> str;
    int goal;
    int sum{ 0 };
    int coe{ 1 };

    for (int i = 0; i < 13; i++)
    {
        if (str[i] == '*')
        {
            if (i % 2 == 1)
                coe = 3;
            continue;
            
        }
        int temp = str[i] - '0';
        if (i % 2 == 1)
            temp *= 3;

        sum += temp;
    }

    for (int i = 0; i < 10; i++)
    {
        if ((sum + i*coe) % 10 == 0){
            goal = i;
            break;
        }
    }
    std::cout << goal << '\n';

    return 0;
}