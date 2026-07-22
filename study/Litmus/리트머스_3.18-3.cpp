#include <iostream>
#include <bits/stdc++.h>

std::queue<int> q;

int main(void)
{
    double row;
    int col;
    double mid_row, mid_col;   //좌표별 중앙 행, 중앙 열과의 거리
    std::cin >> row;

    col = row;
    if (col % 2 == 0)
        col--;

    for (int i = 0; i < row; i++)
    {
        mid_row = (row - 1) / 2;
        mid_row -= i;
        if (mid_row < 0)
            mid_row = -mid_row;

        for (int j = 0; j < col; j++)
        {
            mid_col = (col - 1) / 2;
            mid_col -= j;
            if (mid_col < 0)
                mid_col = -mid_col;

            if (mid_row - 0.5 <= mid_col)
                std::cout << '*';
            else
                std::cout << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}