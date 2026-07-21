#include <iostream>
#include <vector>

std::vector<int> arr = { 1, 2, 3, 4 };
std::vector<int> selected;
std::vector<bool> use;
int n = arr.size();

void subsequence(int index)
{
    if (index == n) {
        for (int x : selected)
            std::cout << x << ' ';
        std::cout << '\n';
        return;
    }

    selected.push_back(arr[index]);
    subsequence(index+1);
    selected.pop_back();
    subsequence(index+1);

}

int main(void) {
    subsequence(0);
    return 0;
}