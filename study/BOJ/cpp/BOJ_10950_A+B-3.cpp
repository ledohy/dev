#include <iostream>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    int a, b;
    while (T--) {
        std::cin >> a >> b;
        std::cout << a + b << '\n';
    }
}