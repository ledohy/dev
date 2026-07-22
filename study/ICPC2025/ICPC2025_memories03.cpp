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

    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j >= i; j--)
        {
            int a_idx = i;
            int b_idx = i;
            int a_min = a[i];
            int b_min = b[i];

            for (int k = i; k <= j; k++)
            {
                if (a[k] <= a_min)
                {
                    a_idx = k;
                    a_min = a[k];
                }
                if (b[k] <= b_min)
                {
                    b_idx = k;
                    b_min = b[k];
                }
            }

            if (a_idx != b_idx)
                continue;

            else
            {
                i += j - i;
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}