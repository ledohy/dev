#include <bits/stdc++.h>

std::stack<std::pair<int, int>> st;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, arr[1000002] = { 0, };
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
        if (i == 0)
            continue;
        else{
            if (arr[i] < st.top().first)
            {
                st.push( {arr[i], i} );
            }
        }
    }

    return 0;
}