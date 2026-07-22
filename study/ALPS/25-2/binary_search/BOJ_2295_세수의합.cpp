#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v;
    int n, input;
    
    std::cin >> n;
    for (int i = 0;i < n; i++)
    {
        std::cin >> input;
        v.push_back(input);
    }
    
    
}