#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> forward;
std::unordered_map<int, std::string> reverse;

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    int pokemon, quiz;

    std::cin >> pokemon >> quiz;
    for (int i = 1; i <= pokemon; i++)
    {
        std::cin >> input;
        forward[input] = i;
        reverse[i] = input;
    }

    while (quiz--)
    {
        std::cin >> input;
        if (0 < input[0] - '0' && input[0] - '0' < 10)
        {
            int temp = std::stoi(input);
            std::cout << reverse[temp] << '\n';
        }
        else
        {
            std::cout << forward[input] << '\n';
        }
    }

    return 0;
}