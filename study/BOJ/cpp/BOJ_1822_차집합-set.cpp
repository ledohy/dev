#include <iostream>
#include <set>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::set<int> s;
    int a, b, input;
    std::cin >> a >> b;

    for (int i = 0; i < a; i++) {
        std::cin >> input;
        s.insert(input);
    }

    for (int i = 0; i < b; i++) {
        std::cin >> input;
        s.erase(input);
    }

    std::cout << s.size() << '\n';
    for (auto it : s)
        std::cout << it << ' ';

    return 0;
}