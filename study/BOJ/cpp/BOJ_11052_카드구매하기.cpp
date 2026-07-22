// #include <iostream>
// int arr[1002];
// int max;

// int indexMake(int idx)
// {
//     if (idx == 1)
//         return arr[idx];
    
    

//     int empty;
//     for (int i = idx - 1; i > idx / 2; i--)
//     {
//         empty = indexMake(idx - i);
//         if (empty + arr[i] > max)
//             max = empty + arr[i];
//     }
//     return max;
// }

// int main(void)
// {   
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int n; 
//     std::cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         std::cin >> arr[i];
//     }

//     max = arr[n];
//     indexMake(n);
//     std::cout << max <<std::endl;

//     return 0;
// }

#include <iostream>

int main(void)
{
    int n, p[1002] = { 0, };
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> p[i];
    }

    

    return 0;
}