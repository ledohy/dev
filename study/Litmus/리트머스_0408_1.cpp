#include <iostream>
#include <queue>

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

char board[52][52];
int dist[52][52];

int main(void)
{
   int n, m, result = 0;
   std::queue<std::pair<int, int>> pos;
   std::cin >> n >> m;
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> board[i][j];
            if (board[i][j] == 'S'){
                pos.push( { i,j } );
                dist[i][j] = 1;
            }
        }
    }

    while (true)
    {
        if (pos.empty())
            break;

        int x = pos.front().first;
        int y = pos.front().second;
        if (board[x][y] == 'T')
        {
            std::cout << dist[x][y] << std::endl;
            return 0;
        }
        pos.pop();

        for (int idx = 0; idx < 4; idx++)
        {
            int nx = x + dx[idx];
            int ny = y + dy[idx];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            else if (board[nx][ny] == '1' || board[nx][ny] == 'S')
                continue;
            
            else if (dist[nx][ny] != 0)
                continue;

            dist[nx][ny] = dist[x][y] + 1;
            pos.push({ nx, ny });            
        }
    }
    std::cout << result << std::endl;

    return 0;
}