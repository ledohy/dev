#include <iostream>
#include <queue>
#include <set>
#include <unordered_map>

std::queue<int> q;
std::set<int> s;
std::unordered_map<int, int> m;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, input, count{0};
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        q.push(input);
        s.insert(input);
    }
    for (auto it : s)
        m[it] = count++;

    while (!q.empty())
    {
        std::cout << m[q.front()] << ' ';
        q.pop();
    }
    std::cout << '\n';

    return 0;
}