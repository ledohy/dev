#include <iostream>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int height, width;
    for (int i = 1; i < 2*n; i++) {
        height = n - i;
        if (height < 0) height = -height;

        for (int j = 1; j < 2*n - height; j++) {
            width = n - j;
            if (width < 0) width = -width;

            if (height + width < n)
                std::cout << '*';
            else
                std::cout << ' ';
        }
        std::cout << '\n';
    }
}