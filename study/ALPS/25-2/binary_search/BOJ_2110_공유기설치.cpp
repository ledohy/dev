#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v;
    int n, c, input;

    std::cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        v.push_back(input);
    }

    std::sort(v.begin(), v.end());


}