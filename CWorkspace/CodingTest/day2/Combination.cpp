#include <iostream>
#include <vector>

std::vector<int> arr = { 1, 2, 3, 4 };
std::vector<int> selected;
int n = arr.size();
int r = 2;

void combination(int start)
{
    if (selected.size() == r) {
        for (int x : selected)
            std::cout << x << ' ';
        std::cout << '\n';
        return;
    }

    for (int i = start; i < n; i++) {
        selected.push_back(arr[i]);
        combination(i+1);
        selected.pop_back();
    }
}

int main(void) {
    combination(0);
    return 0;
}