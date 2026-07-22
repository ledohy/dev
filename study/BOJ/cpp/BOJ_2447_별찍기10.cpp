#include <iostream>

char board[2200][2200];

void star_stamp(int n, int x, int y)
{
    for (int i = x; i < x + n; i += n/3) 
    {
        for (int j = y; j < y + n; j += n/3) 
        {
            if (i == x + n/3 && j == y + n/3)
                continue;
            else {
                if (n == 3)
                    board[i][j] = '*';
                else
                    star_stamp(n/3, i, j);
            }
        }
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++) 
        std::fill(board[i], board[i] + n, ' ');
        
    star_stamp(n, 0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            std::cout << board[i][j];
        std::cout << '\n';
    }

    return 0;
}