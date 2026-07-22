#include <iostream>
#include <stack>
#include <queue>

std::stack<int> s;
std::queue<char> q;
int n, input;
int count;
bool no;

void minus(int data)
{
    if (s.top() == data)
    {
        s.pop();
        q.push('-');
    }
    else
        no = true;
}

void plus(int data)
{
    if (s.empty())
    {
        s.push(++count);
        q.push('+');
    }
    while (s.top() < data)
    {
        s.push(++count);
        q.push('+');
    }
    minus(input);

    if (count > input)
        no = true;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> input;

        if (s.empty())
            plus(input);
        else if (s.top() < input)
            plus(input);
        else if (s.top() == input)
            minus(input);
        else 
            no = true;
    }
    if (no)
        std::cout << "NO" << '\n';
    else
        while (!q.empty())
        {
            std::cout << q.front() << '\n';
            q.pop();
        }

    return 0;
}