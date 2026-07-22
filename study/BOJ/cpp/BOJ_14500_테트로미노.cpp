#include <iostream>

int board[501][501];
int n, m;
int max;

void one_by_four();
void four_by_one();
void two_by_two();
void two_by_three();
void three_by_two();

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> board[i][j];

    one_by_four();
    four_by_one();
    two_by_two();
    two_by_three();
    three_by_two();

    std::cout << max << '\n';
    
    return 0;
}

void one_by_four()
{
    int temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 3; j++)
        {
            temp = board[i][j] + board[i][j+1] + board[i][j+2] + board[i][j+3];
            if (max < temp)
                max = temp;
        }
    }
}
void four_by_one()
{
    int temp;
    for (int i = 0; i < n - 3; i++) {
        for (int j = 0; j < m; j++) 
        {
            temp = board[i][j] + board[i+1][j] + board[i+2][j] + board[i+3][j];
            if (max < temp)
                max = temp;
        }
    }
}
void two_by_two()
{
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++)
        {
            temp = board[i][j] + board[i+1][j] + board[i][j+1] + board[i+1][j+1];
            if (max < temp)
                max = temp;
        }
    }
}
void two_by_three()
{
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int line = 1 - k;
                for (int l = 0; l < 3; l++)
                {
                    temp = 0;
                    temp += board[i+k][j+l];
                    temp += board[i+line][j] + board[i+line][j+1] + board[i+line][j+2];
                    if (max < temp)
                        max = temp;
                }
            }
            temp = board[i][j] + board[i][j+1] + board[i+1][j+1] + board[i+1][j+2];
            if (max < temp)
                    max = temp;

            temp = board[i+1][j] + board[i][j+1] + board[i+1][j+1] + board[i][j+2];
            if (max < temp)
                    max = temp;
        }
    }
}
void three_by_two()
{
    int temp;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                int line = 1 - k;
                for (int l = 0; l < 3; l++)
                {
                    temp = 0;
                    temp += board[i+l][j+k];
                    temp += board[i][j+line] + board[i+1][j+line] + board[i+2][j+line];
                    if (max < temp)
                        max = temp;
                }
            }
            temp = board[i][j] + board[i+1][j] + board[i+1][j+1] + board[i+2][j+1];
            if (max < temp)
                    max = temp;

            temp = board[i][j+1] + board[i+1][j] + board[i+1][j+1] + board[i+2][j];
            if (max < temp)
                    max = temp;
        }
    }
}