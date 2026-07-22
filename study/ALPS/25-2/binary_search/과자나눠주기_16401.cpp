#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define r_iter reverse_iterator

ll longest;

void binary_search(std::vector<ll>& v, ll low, ll high, int m)
{
    ll size;
    ll count;
    bool can;

    while (low <= high)
    {
        size = (low+high)/2;
        count = 0;
        can = false;

        for (std::vector<ll>::r_iter it = v.rbegin(); it != v.rend(); it++)
        {
            count += *it / size;
            if (count >= m) {
                can = true;
                break;
            }
        }

        if (can) {
            if (longest < size)
                longest = size;

            low = size+1;
        }
        else
            high = size-1;
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<ll> v;
    int m, n;
    ll max = 0;
    ll input;
    
    std::cin >> m >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> input;
        v.push_back(input);

        if (input > max) max = input;
    }

    std::sort(v.begin(), v.end());

    binary_search(v, 1, max, m);
        
    std::cout << longest << '\n';

    return 0;
}