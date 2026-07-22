#include <iostream>

int total = 1;
int blue, white;
int paper[129][129] = { 0, };
void cut(int, int, int, int);

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, jump;
    std::cin >> n;
    jump = n / 2;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> paper[i][j];

    cut(n, jump, 0, 0);
    std::cout << total - blue << '\n';
    std::cout << blue << '\n';
    return 0;
}

void cut(int n, int jump, int h, int w)
{
    bool flag = true;
    for (int i = h; i < h + n; i++)
    {
        if ( (i < h + n - 1) && (paper[i][w] != paper[i + 1][w]) )
            {  
                 flag = false;
                 break;
            }

        for (int j = w; j < w + n - 1; j++)
            if (paper[i][j] != paper[i][j + 1])
                {
                    flag = false;
                    break;
                }
    }
    if (flag == true)
    {
        if (paper[h][w] == 1)
            blue++;

        //else white++;
    }

    if (flag == false)
    {
        total += 3;
        for (int i = h; i < h + n; i += jump)
            for (int j = w; j < w + n; j += jump)
                cut(n / 2, jump / 2, i, j);
    }
}