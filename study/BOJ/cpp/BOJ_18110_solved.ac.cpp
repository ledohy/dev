#include <iostream>
#include <queue>

int rounding(double val)
{
    int intager = val;
    val -= intager;
    if (val >= 0.5)
        return intager + 1;
    else
        return intager;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<int> pq;
    double n;
    int input, result{0};

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        pq.push(input);
    }

    int cut = rounding(n * 0.15);

    for (int i = 0; i < cut; i++)
        pq.pop();

    double sum = 0, size = pq.size() - cut;

    for (int i = 0; i < size; i++) {
        sum += pq.top();
        pq.pop();
    }

    if (size != 0)
        result = rounding(sum/size);

    std::cout << result << '\n';

    return 0;
}