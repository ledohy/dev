#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#define ll long long

std::tuple<ll, ll, ll> result;

void binary_search()
{

}

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<ll> v;
    ll input;
    int n;
    
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {   
        std::cin >> input;
        v.push_back(input);
    }

    std::sort(v.begin(), v.end());

    binary_search();

    std::cout << std::get<0>(result) << ' ';
    std::cout << std::get<1>(result) << ' ';
    std::cout << std::get<2>(result) << ' ';

    return 0;
}