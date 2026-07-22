#include <iostream>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n;
    int sol[12];

    sol[1] = 1; sol[2] = 2; sol[3] = 4;
    for (int i = 4; i <= 10; i++)
        sol[i] = sol[i-1] + sol[i-2] + sol[i-3];

    std::cin >> t;
    while (t--) {
        std::cin >> n;
        std::cout << sol[n] << '\n';
    }

    return 0;
}