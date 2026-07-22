#include <iostream>
#define r 31
#define M 1234567891


int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int L;
    unsigned long long result{0}, coef{1};
    std::string str;

    std::cin >> L;
    std::cin >> str;
    for (int i = 0; i < L; i++)
    {
        str[i] -= 96;
        coef = 1;
        for (int j = 0; j < i; j++)
        {
            coef *= r;
            coef %= M;
        }
        
        result += str[i] * coef % M;
    }
    std::cout << result << '\n';

    return 0;
}