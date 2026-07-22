#include <iostream>
#include <vector>
#include <queue>

std::vector<std::pair<int,int>> v[10002];
std::queue<int> q;
int diameter;

int BFS(std::pair<int,int> par) //first: 인덱스, second: 부모로부터의 가중치
{
    if (v[par.first].empty())
        return par.second;

    std::priority_queue<int> pq;
    for (auto nxt : v[par.first]) {
        pq.push( BFS(nxt));
    }

    int biggest = pq.top(); pq.pop();

    if (pq.empty())
        return biggest + par.second;

    if ( diameter < biggest + pq.top() )
        diameter = biggest + pq.top();

    return biggest + par.second;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    int par, chd, height;
    
    std::cin >> n;
    for (int i = 1; i < n; i++)
    {
        std::cin >> par >> chd >> height;
        v[par].push_back( {chd,height} );
    }

    int temp = BFS( {1,0} );
    if (diameter < temp)
        diameter = temp;

    std::cout << diameter << '\n';

    return 0;
}