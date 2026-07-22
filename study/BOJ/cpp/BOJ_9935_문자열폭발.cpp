#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
queue<int> q;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str, tg, ans;
    cin >> str >> tg;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == tg[i]) {
            if (str.substr(i,tg.length()) == tg) i += tg.length();
            else q.push(i);
        }
    }
    
}