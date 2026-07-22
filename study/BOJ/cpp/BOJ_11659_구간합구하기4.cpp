#include <iostream>
#include <vector>

int main(void)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> v;
    int n, m;
    int input, begin, end;
    int panel[102] = { 0, };
    
    std::cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        panel[i/1000] += input;
        v.push_back(input);
    }

    for (int i = 0; i < m; i++)
    {
        std::cin >> begin >> end;
        begin--; end--;
        int sum{0};
        
        if (begin/1000 != end/1000)
        {
            for (int pri = begin/1000 + 1; pri < end/1000; pri++)
                sum += panel[pri];
            while (1)
            {
                sum += v[begin++];
                if (begin % 1000 == 0)
                    break;
            }
                
            while (1)
            {
                sum += v[end];
                if (end % 1000 == 0)
                    break;
                end--;
            }
                
        }
        else
        {
            while (begin <= end)
            {
                if (begin == end)
                    sum -= v[begin];
                sum += v[begin++] + v[end--];
                
            }
        }
        
        std::cout << sum << '\n';
    }

    return 0;
}