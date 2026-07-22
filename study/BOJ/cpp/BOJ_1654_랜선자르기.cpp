#include <iostream>
#include <vector>



int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v;
    int k, n, input;

    std::cin >> k >> n;

    for (int i = 0; i < k; i++)
    {
        std::cin >> input;
        v.push_back(input);
    }

    
}