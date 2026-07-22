#include <iostream>
#include <queue>
#include <stack>

std::priority_queue<std::pair<int, int>> pq;
std::stack<std::pair<int, int>> st;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int fir, sec;

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> fir >> sec;
        pq.push( {sec, fir} );
    }

    while (!pq.empty())
    {
        st.push(pq.top());
        pq.pop();
    }
    while (!st.empty())
    {
        std::cout << st.top().second << ' ' << st.top().first << '\n';
        st.pop();
    }
    
    return 0;
}