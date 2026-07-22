#include <iostream>
#include <queue>
#include <tuple>

std::queue<std::tuple<int,int,int>> q;
int tmt[101][101][101];
int day;

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, n, h;
    std::cin >> m >> n >> h;

    for (int i = 0; i < h; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < m; k++) {
                std::cin >> tmt[k][j][i];
                if (tmt[k][j][i] == 1)
                    q.push( {k,j,i} );
            }
        }
    }

    while (!q.empty()) {
        std::tuple<int,int,int> cur = q.front(); q.pop();

        for (int dir = 0; dir < 6; dir++) {
            int nx = std::get<0>(cur) + dx[dir];
            int ny = std::get<1>(cur) + dy[dir];
            int nz = std::get<2>(cur) + dz[dir];
            
            if (nx < 0 || ny < 0 || nz < 0)
                continue;
            if (nx >= m || ny >= n|| nz >= h)
                continue;
            if (tmt[nx][ny][nz] == -1)
                continue;
            if (tmt[nx][ny][nz] != 0 && tmt[nx][ny][nz] <= tmt[std::get<0>(cur)][std::get<1>(cur)][std::get<2>(cur)] + 1)
                continue;

            tmt[nx][ny][nz] = tmt[std::get<0>(cur)][std::get<1>(cur)][std::get<2>(cur)] + 1;
            q.push({nx,ny,nz});
        }
    }

    bool imposible = false;
    for (int i = 0; i < h; i++) 
        for (int j = 0; j < n; j++) 
            for (int k = 0; k < m; k++) {
                if (tmt[k][j][i] == 0)
                    imposible = true;
                if (day < tmt[k][j][i])
                    day = tmt[k][j][i];
            }

    if (day != 0)
        day--;
        
    if (imposible) std::cout << -1;
    else           std::cout << day;

    std::cout << '\n';

    return 0;
}