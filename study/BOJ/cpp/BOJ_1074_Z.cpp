#include <iostream>
int Z(int , int , int );

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, r, c;
    std::cin >> n >> r >> c;
    std::cout << Z(n, r, c) << '\n';

    return 0;
}

int Z(int n, int r, int c)
{
    if (n == 0)
    {

    }

    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            rr -= nn / 4;
        }
        if (i == 1)
        {
            rr -= 2^(nn - 1) - 1;
            cc++;
        }
        if (i == 2)
        {
            rr++;
            cc -= 2^(nn) - 1;
        }
        if (i == 3)
        {

        }
    }
}
