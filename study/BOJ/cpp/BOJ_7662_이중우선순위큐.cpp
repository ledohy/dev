#include <iostream>
#include <queue>

std::priority_queue<int> pq1;
std::priority_queue<int, std::vector<int>, std::greater<int> > pq2;

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    char order;
    int t, n, num;
    int size{0};

    std::cin >> t;
    while (t--) {
        while (!pq1.empty())
            pq1.pop();
        while (!pq2.empty())
            pq2.pop();

        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> order >> num;

            if (order == 'I') {
                size++;
                pq1.push(num);
                pq2.push(num);
            }
            else {
                if (size == 0)
                    continue;
                
                if (--size == 0) {
                    while (!pq1.empty())
                        pq1.pop();
                    while (!pq2.empty())
                        pq2.pop();
                }
                else {
                    if (num == 1)
                        pq1.pop();
                    else
                        pq2.pop();
                }
            }
        }
        if (size == 0)
            std::cout << "EMPTY\n";
        else
            std::cout << pq1.top() << ' ' << pq2.top() << '\n';
    }

    return 0;
}