#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

ll count;

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v;
    int n, input;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> input;
        v.push_back(input);
    }

    std::sort(v.begin(), v.end());

    int pivot1, pivot2, target;

    for (int i = 0; i < n-2; i++) 
    {
        pivot1 = v[i];
        for (int j = i+1; j < n-1; j++) 
        {
            pivot2 = v[j];
            target = -(pivot1 + pivot2);
            count += upper_bound(v.begin()+j+1, v.end(), target) - lower_bound(v.begin()+j+1, v.end(), target);
        }
    }


    std::cout << count << '\n';

    return 0;
}