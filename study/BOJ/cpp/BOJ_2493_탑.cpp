#include <iostream>
#include <queue>
#include <stack>

std::queue<int> result;
std::stack<std::pair <int, int>> s;
int building[500002] = { 100000001 };

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i = 1; i <= n; i++)
        std::cin >> building[i];

    for (int i = 0; i < n; i++)
    {
        if (building[i] >= building[i+1])
        {
            s.push( {building[i], i} );
        }
        else
        {
            while (s.top().first < building[i+1])
                s.pop();
        }

        result.push( s.top().second );
    }

    while (!result.empty())
    {
        std::cout << result.front() << ' ';
        result.pop();
    }
    std::cout << '\n';

    return 0;
}