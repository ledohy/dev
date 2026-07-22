#include <iostream>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int num, room[9] = { 0, };
    std::cin >> num;
    
    int sol, max = 0;
    while (num > 0) {
        sol = num % 10;
        if (sol == 9)
            sol = 6;
        room[sol]++;
        num /= 10;
    }
    room[6] = (room[6] + 1) / 2;
    for (int i = 0; i < 9; i++)
        if (max < room[i])
            max = room[i];
    std::cout << max << '\n';
    return 0;
}