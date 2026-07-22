#include <iostream>
#include <queue>
#include <vector>

std::vector<std::pair<int,int>> v[100003]; //visited를 써보자
int n, diameter;

int DFS(std::pair<int,int> par) //우선순위큐를 쉽게 쓰기위해 first가 가중치, second가 인덱스
{
    if (v[par.second].empty())
        return par.first;

    std::priority_queue<int> pq;
    int biggest;

    for (auto nxt : v[par.second]) {
        pq.push( DFS(nxt) );
    }

    biggest = pq.top(); pq.pop();
    if (pq.empty())
        return biggest;

    if (diameter < biggest + pq.top())
        diameter = biggest + pq.top();

    return biggest + par.first;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int par;
    int chd, height;

    std::cin >> n;

    for (int i = 1; i <= n; i++) 
    {
        std::cin >> par;
        while (1) 
        {
            std::cin >> chd;
            if (chd == -1) break;
            std::cin >> height;
            v[par].push_back( {height, chd} );
        }
    }
    int temp = DFS( {0,1} );

    if (diameter < temp)
        diameter = temp;

    std::cout << diameter << '\n';

    return 0;
}