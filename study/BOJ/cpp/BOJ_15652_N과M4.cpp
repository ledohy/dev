#include <iostream>
#include <vector>
#include <set>

std::vector<int> v;
std::set<std::vector<int>> result;
int n, m;

void tracking(int idx, int count)
{
    if (count >= m) {
        result.insert(v);
        return;
    }

    for (int i = idx; i <= n; i++) {
        v.push_back(i);
        tracking(i, count+1);
        v.pop_back();
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n >> m;

    tracking(1, 0);

    for (auto it : result) { 
        for (auto it_v :  it) {
            std::cout << it_v << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}