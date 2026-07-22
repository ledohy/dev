#include <iostream>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m = 100, sum = 0, input;
    for (int i = 0; i < 7; i++) {
        std::cin >> input;
        if (input % 2 == 0) 
            continue;

        if (m > input) 
            m = input;
        sum += input;
    }
    if (m == 100)
        std::cout << -1 << '\n';
    else {
        std::cout << sum << '\n';
        std::cout << m << '\n';
    }
    return 0;
}