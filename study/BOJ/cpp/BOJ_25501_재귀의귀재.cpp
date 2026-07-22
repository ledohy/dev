#include <iostream>
#include <cstring>

std::pair<int, int> recursion(const char *str, int l, int r)
{
    if (l >= r)
    {
        return {1, l + 1};
    }
    else if (str[l] != str[r])
    {
        return {0, l + 1};
    }
    else
        return recursion(str, l + 1, r - 1);
}

std::pair<int, int> isPalindrome(const char *str)
{
    return recursion(str, 0, strlen(str) - 1);
}

int main()
{
    int n;
    std::pair<int, int> result;
    std::string str;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> str;
        result = isPalindrome(&str[0]);
        std::cout << result.first << ' ' << result.second << '\n';
    }
    return 0;
}