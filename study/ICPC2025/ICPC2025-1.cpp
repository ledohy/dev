#include <iostream>
using namespace std;
int n, a[3005], b[3005];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int cnt = 1;
    
    for (int i = 2; i < n; i++)
    {
        if (a[i-2] < a[i-1] && a[i-1] > a[i] || a[i-2] > a[i-1] && a[i-1] < a[i])
        {
            if (b[i-2] < b[i-1] && b[i-1] < b[i])
                cnt++;
                if (b[i-2] > b[i-1] && b[i-1] > b[i])
                cnt++;
        }

        if (b[i-2] < b[i-1] && b[i-1] > b[i] || b[i-2] > b[i-1] && b[i-1] < b[i])
        {
            if (a[i-2] < a[i-1] && a[i-1] < a[i])
            cnt++;
            if (a[i-2] > a[i-1] && a[i-1] > a[i])
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}