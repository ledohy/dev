#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <set>

std::set<std::vector<int>> result;
std::unordered_set<int> used;
std::vector<int> v, test;
int n, m;

void print_array()
{
    for (auto it : result) {
        for (int cur : it) {
            std::cout << cur << ' ';
        }
        std::cout << '\n';
    }
}

void make_array(int count)
{
    if (count == m) {
        result.insert(test);
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (used.find(i) != used.end())
            continue;

        test.push_back(v[i]);
        used.insert(i);
        make_array(count+1);
        test.pop_back();
        used.erase(i);
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int input;

    std::cin >> n >> m;

    for (int i = 0; i < n; i++) {
        std::cin >> input;
        v.push_back(input);
    }

    std::sort(v.begin(), v.end());

    make_array(0);
    print_array();

    return 0;
}