#include <iostream>
#include <algorithm>
#include <vector>
#define r_it reverse_iterator
#define ll long long

ll binary_search(std::vector<ll>& v, ll low, ll high, ll goal)
{
    ll longest = 0;
    ll middle;
    ll count;
    bool can;

    while (low <= high)
    {
        middle = low + (high-low)/2;
        count = 0;
        can = false;

        for (std::vector<ll>::r_it it = v.rbegin(); it != v.rend(); it++)
        {
            count += *it / middle;
            if (count >= goal) {
                can = true;
                break;
            }
        }

        if (can)
        {
            if (middle > longest)
                longest = middle;

            low = middle + 1;
        }
        else
            high = middle - 1;
        
    }

    return longest;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<ll> v;
    ll k, n, input;
    ll max = 0;
    
    std::cin >> k >> n;
    for (ll i = 0; i < k; i++)
    {
        std::cin >> input;
        v.push_back(input);

        if (input > max) max = input;
    }

    std::sort(v.begin(), v.end());

    std::cout << binary_search(v, 1, max, n) << '\n';

    return 0;
}