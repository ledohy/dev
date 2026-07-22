#include <iostream>
#include <vector>

std::vector<int> arr = { 1, 2, 3, 4 };
std::vector<int> selected;
std::vector<bool> visited(4, false);
int n = arr.size();
int r = 2;

void permutation()
{
    if (selected.size() == r) {
        for (int x : selected)
            std::cout << x << ' ';
        std::cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        selected.push_back(arr[i]);
        visited[i] = true;
        permutation();
        selected.pop_back();
        visited[i] = false;
    }
}

int main(void) {
    permutation();
    return 0;
}