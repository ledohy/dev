#include <iostream>

void hanoi(int ,int ,int);

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, count = 0;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        count = 2 * count + 1;

    std::cout << count << '\n';
    hanoi(n, 2, 3);

    return 0;
}

void hanoi(int n, int tower, int target)
{
    if (n != 1)
        hanoi(n - 1, 6 - target - tower, target, tower);
    
    std::cout << 6 - target - tower << ' ' << target << '\n';

    if (n != 1)
        hanoi(n - 1, tower, 6 - target - tower, target);
    #include <iostream>

void hanoi(int ,int ,int ,int);

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, count = 0;
    std::cin >> n;

    for (int i = 0; i < n; i++)
        count = 2 * count + 1;

    std::cout << count << '\n';
    hanoi(n, 1, 2, 3);

    return 0;
}

void hanoi(int n, int start, int tower, int target)
{
    if (n != 1)
        hanoi(n - 1, start, target, tower);
    
    std::cout << start << ' ' << target << '\n';

    if (n != 1)
        hanoi(n - 1, tower, start, target);
    
    return;
}
    return;
}