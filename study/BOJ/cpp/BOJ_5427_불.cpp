#include <iostream>
#include <queue>
#define X first
#define Y second

std::queue<std::pair<int, int>> man;
std::queue<std::pair<int, int>> fq;
char map[1002][1002];
int fmap[1002][1002];
int moved[1002][1002];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, dist{ 1000000 };
    std::cin >> n;
    
    int w, h;

    while (n--)
    {
        dist = 1000000;
        while (!man.empty()) man.pop();
        while (!fq.empty()) fq.pop();


        std::cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                std::cin >> map[i][j];
                moved[i][j] = 0;
                fmap[i][j] = 0;

                if (map[i][j] == '@')
                {
                    man.push( {i,j} );
                    moved[i][j] = 1;
                }
                if (map[i][j] == '*')
                {
                    fq.push( {i,j} );
                    fmap[i][j] = 1;
                }
            }
        }
        while (!fq.empty())
        {
            std::pair<int, int> fire = fq.front(); fq.pop();

            for (int nxt = 0; nxt < 4; nxt++)
            {
                int nx = fire.X + dx[nxt];
                int ny = fire.Y + dy[nxt];

                if (nx < 0 || nx >= h) continue;
                if (ny < 0 || ny >= w) continue;
                if (map[nx][ny] == '#') continue;
                if (fmap[nx][ny] <= fmap[fire.X][fire.Y] + 1 && fmap[nx][ny] != 0) continue;

                fmap[nx][ny] = fmap[fire.X][fire.Y] + 1;
                fq.push( {nx, ny} );
            }
        }
        
        while (!man.empty())
        {
            std::pair<int, int> lc = man.front(); man.pop();

            for (int nxt = 0; nxt < 4; nxt++)
            {
                int nx = lc.X + dx[nxt];
                int ny = lc.Y + dy[nxt];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w) 
                {
                    if (moved[lc.X][lc.Y] < dist)
                        dist = moved[lc.X][lc.Y];
                    
                    continue;
                }
                if (map[nx][ny] == '#') continue;
                if (moved[nx][ny] <= moved[lc.X][lc.Y] + 1 && moved[nx][ny] != 0) continue;
                if (moved[lc.X][lc.Y] + 1 >= fmap[nx][ny] && fmap[nx][ny] != 0) continue;

                moved[nx][ny] = moved[lc.X][lc.Y] + 1;
                man.push( {nx, ny} );
            }

        }

        if (dist == 1000000)
            std::cout << "IMPOSSIBLE" << '\n';
        else
            std::cout << dist << '\n';
    }

    return 0;
}