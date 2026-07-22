#include <iostream>

void time(int h, int m = 0, int s = 0)
{
    if (h < 0 || m < 0 || s < 0) {
        std::cout << "incorrect number\n";
        return;
    }
    m += h * 60;
    s += m * 60;
    std::cout << s << '\n';
    return;
}

int main(void) {
    int menu;
    std::cin >> menu;
    if (menu < 1 || menu > 4) {
        std::cout << "wrong menu\n";
        return 0;
    }

    int tm[4] = { 0, };
    for (int i = 1; i < menu; i++) 
        std::cin >> tm[i];
    time(tm[1], tm[2], tm[3]);

    return 0;
}