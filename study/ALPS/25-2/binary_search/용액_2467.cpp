#include <iostream>
#include <vector>
#include <climits>
#define ll long long

int binary_search(std::vector<ll>& list, int low, int high, ll target);

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<ll> list;
    std::pair<ll, ll> result;
    ll input, min = LLONG_MAX;
    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        list.push_back(input);
    }

    for (int pivot = 0; pivot < n; pivot++)
    {
        int idx = binary_search(list, pivot+1, list.size()-1, list[pivot]);
        
        ll temp = list[pivot] + list[idx];
        if (temp < 0)
            temp = -temp;
    
        if (min >= temp) {
            min = temp;
            result = { list[pivot], list[idx] };
        }
    }

    if (result.first > result.second) {
        ll temp = result.first;
        result.first = result.second;
        result.second = temp;
    }

    std::cout << result.first << ' ' << result.second << '\n';

    return 0;
}

int binary_search(std::vector<ll>& list, int low, int high, ll target)
{
    ll min = LLONG_MAX;
    ll sum, abs;
    int mid = (low+high)/2;
    int mid_min;

    while (low <= high)
    {
        sum = target + list[mid];
        abs = (sum >= 0) ? sum : -sum;

        if (abs < min) {
            min = abs;
            mid_min = mid;
        }

        if (sum == 0) return mid;

        if (sum < 0) low = mid + 1;
        if (sum > 0) high = mid - 1;
        mid = (low+high)/2;
    }
    return mid_min;
}