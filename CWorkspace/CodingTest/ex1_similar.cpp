#include <iostream>
#include <vector>
#include <set>
#include <map> //얘네 이용해봐야함!!

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<std::string> patterns;
    std::vector<std::string> inputs;
    std::string input;
    int n, s, ans = 0;

    std::cin >> n >> s;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        inputs.push_back(input);
        for (int j = 0; j < input.length(); j++) {
            std::string tmp = input;
            tmp[j] = '*';
            patterns.push_back(tmp);
        }
    }

    
}