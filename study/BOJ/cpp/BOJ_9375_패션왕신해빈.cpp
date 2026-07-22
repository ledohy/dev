#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, piece;
    std::string clothes, category;

    std::cin >> n;
    while (n--)
    {
        std::map<std::string, int> dic;
        std::vector<std::string> v;
        int result{1};
        int arr[31] = { 0, };

        std::cin >> piece;

        while (piece--) {
            std::cin >> clothes >> category;
            dic[category]++;
            if (std::find(v.begin(), v.end(), category) == v.end())
                v.push_back(category);
        }

        int idx{0};
        for (auto it : v) 
            arr[idx++] = dic[it] + 1;

        for (int i = 0; i < v.size(); i++) {
            result *= arr[i];
        }

        if (piece != 0)
            result--;
        
        std::cout << result << '\n';
    } 

    return 0;
}