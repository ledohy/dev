#include <iostream>
using namespace std;

int a[1005][1005], b[1005][1005], ab[1005][1005];
int Max[1005];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, input;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> b[i][j];
            temp = a[i][j] - b[i][j];
            if (temp < 0)
                temp = -temp;
            ab[i][j] = temp;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ab[j][i] > Max[i])
                Max[i] = ab[j][i];
        }
    }

    int result = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        result += Max[input-1];
    }
    cout << result << '\n';

    return 0;
}