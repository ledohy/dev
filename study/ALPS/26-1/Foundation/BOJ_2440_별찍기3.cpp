#include <iostream>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i; j++)
            std::cout << '*';
            
        std::cout << '\n';
    }
    return 0;
}