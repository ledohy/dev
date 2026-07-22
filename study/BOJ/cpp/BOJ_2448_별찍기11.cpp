#include <iostream>
#define X first
#define Y second
using namespace std;
char star[6159][6159];

void stamp(pair<int,int> rt, int size) {
    if (size == 3) {
        star[rt.X][rt.Y] = '*';
        star[rt.X+1][rt.Y-1] = star[rt.X+1][rt.Y+1] = '*';
        for (int i = -2; i < 3; i++)
            star[rt.X+2][rt.Y+i] = '*';
        return;
    }
    stamp({rt.X, rt.Y}, size/2);
    stamp({rt.X+size/2, rt.Y-size/2}, size/2);
    stamp({rt.X+size/2, rt.Y+size/2}, size/2);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int size;
    cin >> size;
    for (int i = 1; i <= size; i++) fill(star[i]+1, star[i]+2*size, ' ');
    stamp({1, size}, size);
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= 2*size-1; j++) cout << star[i][j];
        cout << '\n';
    }
}