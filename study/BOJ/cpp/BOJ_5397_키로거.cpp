#include <iostream>
#include <vector>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string input;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        std::vector<char> res;
        std::vector<char>::iterator it = res.begin();
        for (int j = 0; j < input.length(); j++) {
            if (input[j] == '<' && it != res.begin()) 
                it--;
            if (input[j] == '>' && it != res.end()-1)
                it++;
            if (input[j] == '-' && it != res.begin()) {
                res.pop_back();
                it--;
            }
            else 
                res.insert(it, input[j]);
                it++;
        }
        for (int k = 0; k < res.size(); k++)
            std::cout << res[k] << '\n';
    }
    return 0;
}