#include <iostream>
#include <queue>

bool board[101][101];

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::queue<int> q;
    int n;

    std::cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> board[i][j];

    for (int i = 0; i < n; i++) { 
        while (!q.empty())
            q.pop();

        for (int j = 0; j < n; i++) {
            if (board[i][j])
                q.push(j);

            
        }
    }
}