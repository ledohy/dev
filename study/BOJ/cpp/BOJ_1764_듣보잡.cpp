#include <iostream>
#include <unordered_map>
#include <set>

std::unordered_map<std::string, bool> list;
std::set<std::string> result;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::string input;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        list[input] = true;
    }
    
    for (int i = 0; i < m; i++)
    {
        std::cin >> input;
        if (list[input] == true)
            result.insert(input);
    }

    std::cout << result.size() << '\n';
    for (auto it : result)
        std::cout << it << '\n';

    return 0;
}