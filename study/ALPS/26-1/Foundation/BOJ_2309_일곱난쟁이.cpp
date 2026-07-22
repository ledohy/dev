#include <iostream>
#include <algorithm>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cm[9];
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        std::cin >> cm[i];
        sum += cm[i];
    }
    
    std::sort(cm, cm+9);

    int ex[2];
    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 9; j++) {
            if (sum - cm[i] - cm[j] == 100) {
                ex[0] = cm[i];
                ex[1] = cm[j];
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        if (cm[i] == ex[0] || cm[i] == ex[1]) continue;
        std::cout << cm[i] << '\n';
    }
    return 0;
}