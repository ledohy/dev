#include <iostream>
#include <queue>
#define X first
#define Y second

char school[605][605];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::queue< std::pair<int,int> > q;
    int w, h;
    int count{0};
    
    std::cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            std::cin >> school[i][j];
            if (school[i][j] == 'I')
                q.push( {i,j} );
        }

    while (!q.empty())
    {
        std::pair<int,int> pos = q.front(); q.pop();
        
        for (int nxt = 0; nxt < 4; nxt++)
        {
            int nx = pos.X + dx[nxt];
            int ny = pos.Y + dy[nxt];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (school[nx][ny] == 'X' || school[nx][ny] == 'A')
                continue;
            
            if (school[nx][ny] == 'P')
                count++;
            
            school[nx][ny] = 'A';
            q.push( {nx,ny} );
        }
    }

    if (count == 0)
        std::cout << "TT" << '\n';
    else
        std::cout << count << '\n';

    return 0;
}