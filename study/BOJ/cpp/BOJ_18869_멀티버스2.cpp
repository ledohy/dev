#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int,vector<string>>> v[105];
    string change;
    int m, n, input;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> input;
            for (int k = 0; k <= j; k++)
            {
                if (input > v[k].first)
                v[i].push_back(input);
            }
        }

    
}