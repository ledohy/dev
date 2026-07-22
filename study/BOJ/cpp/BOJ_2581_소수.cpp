// #include <iostream>

// int main(void)
// {
//     int start, end, result = 0, min;

//     std::cin >> start >> end;

//     for (int i = end; i >= start; i--)
//     {
//         for (int j = 2; j <= i; j++)
//         {
//             if (j == i)
//             {
//                 result += i;
//                 min = i;
//             }
//             if (i % j == 0)
//                 break;
//         }
//     }

//     if (result == 0)
//     {
//         std::cout << -1 << '\n';
//     }
//     else
//     {
//         std::cout << result << '\n';
//         std::cout << min << '\n';
//     }
//     return 0;
// }

// #include <iostream>

// int main(void)
// {
//     int start, end, result = 0, min;

//     std::cin >> start >> end;

//     for (int i = end; i >= start; i--)
//     {
//         for (int j = 2; j <= i; j++)
//         {
//             if (j == i)
//             {
//                 result += i;
//                 min = i;
//             }
//             if (i % j == 0)
//                 break;
//         }
//     }

//     if (result == 0)
//     {
//         std::cout << -1 << '\n';
//     }
//     else
//     {
//         std::cout << result << '\n';
//         std::cout << min << '\n';
//     }
//     return 0;
// }

#include <iostream>

int main(void)
{
    int start, end, hum{ 0 }, min{ 0 };
    int num[10002] = { 0, };

    std::cin >> start >> end;

    for (int i = start; i <= end; i++)
    {
        if (i != 1)
            num[i] = i;
    }

    for (int i = 2; i <= end; i++)
    {
        for (int j = i + i; j <= end; j += i)
        {
            num[j] = 0;
        }
    }

    for (int i = start; i <= end; i++)
    {
        if (num[i] != 0)
        {
            hum += num[i];
            if (min == 0)
                min = num[i]; 
        }
    }    

    if (hum == 0)
        std::cout << -1 << '\n';
    else
    {
        std::cout << hum << '\n';
        std::cout << min << '\n';
    }
    return 0;
}