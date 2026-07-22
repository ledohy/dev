#include <iostream>
#include <vector>
#define X first
#define Y second

std::vector<std::pair<int,int>> queen;
bool board[15][15];
int n;
int count;
int queen_count;

void recur(int line)
{
    if (line >= n) {
        if (queen_count == n)
            count++;
        return;
    }

    for (int i = 0; i < n; i++) {
        std::pair<int,int> cur = { line,i };

        bool flag = false;
        for (auto it : queen) {
            if (cur.X == it.X || cur.Y == it.Y)
                flag = true;
            int nx = cur.X - it.X;
            int ny = cur.Y - it.Y;
            if (nx < 0) nx = -nx;
            if (ny < 0) ny = -ny;
            if (nx == ny) flag = true;
        }
        if (flag) {
            flag = false;
            continue;
        }

        queen.push_back( {line,i} );
        queen_count++;
        recur(line+1);
        queen.pop_back();
        queen_count--;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    recur(0);

    std::cout << count << '\n';

    return 0;
}