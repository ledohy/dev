#include <iostream>
#include <queue>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::queue<unsigned long long> q;
    unsigned long long arr[101] = { 0, };
    unsigned long long t, num;

    arr[1] = arr[2] = arr[3] = 1;
    arr[4] = arr[5] = 2;
    for (int i = 0; i < 3; i++)
        q.push(1);
    for (int i = 0; i < 2; i++)
        q.push(2);

    for (int i = 6; i <= 100; i++) {
        arr[i] = q.front() + q.back();
        q.push(arr[i]);
        q.pop();
    }

    std::cin >> t;
    while (t--) {
        std::cin >> num;
        std::cout << arr[num] << '\n';
    }

    return 0;
}