#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

std::vector<int> v, selected;
std::set<std::vector<int>> s;
int n, m;

void make_array()
{

}

void make_combination(int count) 
{
    if (count >= m) {
        make_array();
        return;
    }
    
    for (int i = count; i < v.size() - m + 1; i++) {
        selected.push_back(i);
        make_combination(count+1);
        selected.pop_back();
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

    make_combination(0);
}