#include <iostream>
#include <queue>

int arr[8001];
std::priority_queue<int> pq;
std::priority_queue<int, std::vector<int>, std::greater<int>> gq;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, input;
    int sum{0}, aver, middle, freq{0}, range;

    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        sum += input;
        pq.push(input);
        gq.push(input);

        if (input < 0) {
            input = -input;
            input += 4000;
        }
        arr[input]++;
    }

    range = pq.top() - gq.top();

    aver = sum / n;
    if (sum % n * 2 >= n)
        aver++;
    if (sum % n * 2 < -n)
        aver--;
    
    int size = gq.size()/2;
    for (int i = 0; i < size; i++)
        gq.pop();

    middle = gq.top();
    while (!gq.empty())
        gq.pop();
    while (!pq.empty())
        pq.pop();

    for (int i = 0; i < 8001; i++)
    {
        if (freq <= arr[i])
            freq = arr[i];
    }
    for (int i = 0; i < 8001; i++)
    {
        int real = i;
        if (i > 4000)
        {
            real -= 4000;
            real = -real;
        }
        if (freq == arr[i])
            gq.push(real);
    }
    freq = gq.top(); gq.pop();
    if (!gq.empty())
        freq = gq.top();

    std::cout << aver << '\n';
    std::cout << middle << '\n';
    std::cout << freq << '\n';
    std::cout << range << '\n';

    return 0;
}