#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

vector<pair<int,int>> chk, hm;
pair<int,int> city[55][55];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            cin >> city[i][j].second;
            if (city[i][j].second == 1) 
                hm.push_back({i,j});
            if (city[i][j].second == 2) 
                chk.push_back({i,j});
        }
    for(pair<int,int> i : hm) {
        int m = 250;
        pair<int,int> m_i = { 0, 0 };
        for(pair<int,int> j : chk) {
            int x = i.X - j.X;
            int y = i.Y = j.Y;
            if (x < 0) x = -x;
            if (y < 0) y = -y;
            int d = x+y;
            if (m > d) {
                m = d;
                m_i = j;
            }
        }
        city[m_i.first][m_i.second].first++;
    }
}