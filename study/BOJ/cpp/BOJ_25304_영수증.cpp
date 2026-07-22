#include <iostream>
int a[1000][1000];

std::string sum_total(int rpt, int n)
{
    int sum{ 0 };
    int ob, price;
    for (int i = 0; i < n; i++)
    {
        std::cin >> ob >> price;
        sum += ob * price;
    }
    if (rpt == sum)
        return "Yes";
    else
        return "No";
}

std::string min_zero(int rpt, int n)
{
    int ob, price;
    while (n--)
    {
        std::cin >> ob >> price;
        rpt -= ob * price;
    }
    if (rpt == 0)
        return "Yes";
    else
        return "No";
}

int main(void)
{
    int receipt{ 0 };
    int n;
    
    std::cin >> receipt >> n;

    std::cout << sum_total(receipt, n) << std::endl;
    //std::cout << min_zero(receipt, n) << std::endl;

    return 0;
}