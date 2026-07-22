#include <iostream>

int main(void) 
{
    std::cout.precision(10);
    double a, b;
    std::cin >> a >> b;
    double res = a/b;
    std::cout << res << '\n';

    return 0;
}