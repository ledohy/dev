#include <iostream>
#include <queue>

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    std::pair<int,int> dp[10005];
    
    int n, ans = 0;
    int p, d;
    int Max = 0;

    std::cin >> n;
    for (int i = 0; i < n; i++) 
        std::cin >> dp[i].second >> dp[i].first;

    std::sort(dp, dp + n);
    
    if (Max < d) Max = d;
    q.push(p);
    if (Max < q.size()) q.pop();
    int capa = q.size();
    for (int i = 0; i < capa; i++) {
        ans += q.top(); q.pop();
    }
    std::cout << ans << '\n';

    return 0;
}