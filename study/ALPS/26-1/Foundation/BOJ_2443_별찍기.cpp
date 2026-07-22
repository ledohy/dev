#include <iostream>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = n-1; i >= 0; i--) {
        for (int j = 1; j <= n+i; j++) {
            if (n-i <= j && j <= n+i) 
                std::cout << '*';
            else
                std::cout << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}