#include <iostream>

int main(void) {
    int k, d, a;
    char sl;
    
    std::cin >> k >> sl >> d >> sl >> a;
    if (k + a < d || d == 0)
        std::cout << "hasu\n";
    else 
        std::cout << "gosu\n";
    return 0;
}