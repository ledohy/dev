#include <iostream>
#include <queue>
#define X first
#define Y second

std::queue<std::pair<int, int>> q;
int box[1002][1002];    //토마토가 든 박스

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int w,h;
    int day{0};

    std::cin >> w >> h;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
        {
            std::cin >> box[i][j];
            if (box[i][j] == 1)
                q.push( {i,j} );
        }
    }

    while (!q.empty())
    {
        std::pair<int, int> tmt = q.front(); q.pop();

        for (int nxt = 0; nxt < 4; nxt++)
        {
            int nx = tmt.X + dx[nxt];
            int ny = tmt.Y + dy[nxt];

            if (nx < 0 || nx >= h | ny < 0 || ny >= w) //범위나가면 컷
                continue;
            if (box[nx][ny] == -1)                     //토마토가 없으면 컷
                continue;
            if (box[nx][ny] > 0 && box[tmt.X][tmt.Y] + 1 >= box[nx][ny])
                continue;                              //이미 예전에 익어있으면 컷
            
            day = box[nx][ny] = box[tmt.X][tmt.Y] + 1;  //여기까지 왔으면 토마토가 아직 안익었거나
            q.push( {nx,ny} );                          //더 빨리 익는 길을 찾은거임!
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
        {
             if (box[i][j] == 0)        //BFS가 끝났는데도 안익은 토마토가?
             {                          //평생 안익는 토마토가 있다는것
                std::cout << -1 << '\n';
                return 0;
             }
        }
    }

    if (day != 0)   //날짜가 0부터 시작해야하는데 토마토가 1부터 시작하니 빼줘야함
        day--;      //0이면 0을 그대로 출력해야하니 조건문으로 처리

    std::cout << day << '\n';
    
    return 0;
}