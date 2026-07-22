#include <iostream>
#include <vector>
#include <queue>

std::vector<char> v, test;
std::priority_queue<char,std::vector<char>,std::greater<char>> q;
int L, C;

int vow_count()
{
    int count{0};
    for (auto it : test)
        if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u')
            count++;
    
    return count;
}

void print_test()
{
    if (test.size() != L)
        return;

    for (char c : test)
        std::cout << c;
    std::cout << '\n';
}

void recur(int it, int len)
{
    if (len >= L) {
        if (vow_count() >= 1)
            print_test();
            
        return;
    }

    for (int i = it; i < v.size(); i++)
    {
        if (len == 0 && i > C - L)
            continue;

        test.push_back(v[i]);

        if (vow_count() > L - 2) {
            test.pop_back();
            continue;
        }

        recur(i+1, len+1);
        test.pop_back();
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char input;

    std::cin >> L >> C;
    for (int i = 0; i < C; i++) {
        std::cin >> input;
        q.push(input);
    }
    while (!q.empty()) {
        v.push_back(q.top());
        q.pop();
    }

    recur(0, 0);

    return 0;
}