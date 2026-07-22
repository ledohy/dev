#include <iostream>
#include <climits>

void countingSort(int A[], int B[], int n);

int main(void)
{
    int A[10005] = { 0, };
    int B[10005] = { 0, };
    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> A[i];

    countingSort(A, B, n);
}

void countingSort(int A[], int B[], int n)
{
    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < n; i++) 
    {
        if (A[i] > max) max = A[i];
        if (A[i] < min) min = A[i];
    }

    const int k = max - min + 1;
    int C[k];

    for (int i = 0; i <= k; i++)
        C[i] = 0;
    for (int i = 0; i < n; i++)
        C[A[i] - min]++;
    for (int i = 1; i <= k; i++)
        C[i] += C[i-1];
    for (int i = n-1; i >= 0; i--)
    {
        B[C[A[i]-min]] = A[i];
        C[A[i]-min]--;
    }

    for (int i = 1; i <= k; i++)
        std::cout << C[i] << ' ';
    std::cout << '\n';

    return;
}