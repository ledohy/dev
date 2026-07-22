#include <iostream>
#include <algorithm>

int arr[100002];
bool search(int arr[], int low, int high, int target);

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    int input;

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        arr[i] = input;
    }
    std::sort(arr, arr + n);
    
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        std::cin >> input;
        std::cout << search(arr, 0, n - 1, input) << '\n';
    }

    return 0;
}

bool search(int arr[], int low, int high, int target)
{
    if (low > high)
        return false;

    int middle = (high + low) / 2;
    
    if (target == arr[middle])
        return true;
    if (target < arr[middle])
        return search(arr, low, middle - 1, target);
    if (target > arr[middle])
        return search(arr, middle + 1, high, target);
}