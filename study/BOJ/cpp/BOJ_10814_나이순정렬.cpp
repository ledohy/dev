#include <iostream>
#include <map>

std::map<std::pair<int,int>, std::string> m;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int age;
    std::string input;

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> age >> input;
        m[{age,i}] = input;
    }
    for (auto it : m)
    {
        std::cout << it.first.first << ' ';
        std::cout << it.second << '\n';
    }

    return 0;
}