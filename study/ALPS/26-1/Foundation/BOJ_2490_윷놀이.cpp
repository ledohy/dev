#include <iostream>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cnt, input;
    for (int i = 0; i < 3; i++) {
        cnt = 0;
        for (int j = 0; j < 4; j++) {
            std::cin >> input;
            if (input == 0) cnt++;
        }
        switch(cnt) {
            case 1:
                std::cout << "A\n";
                break;
            case 2:
                std::cout << "B\n";
                break;
            case 3:
                std::cout << "C\n";
                break;
            case 4:
                std::cout << "D\n";
                break;
            default:
                std::cout << "E\n";
        }
    }
    return 0;
}