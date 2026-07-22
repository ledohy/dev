#include <iostream>
#include <vector>
#include <unordered_map>

std::unordered_map<std::string, std::string> p;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::string site, pwd;
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        std::cin >> site >> pwd;
        p[site] = pwd;
    }
    for (int i = 0; i < m; i++)
    {
        std::cin >> site;
        std::cout << p[site] << '\n';
    }
    return 0;
}