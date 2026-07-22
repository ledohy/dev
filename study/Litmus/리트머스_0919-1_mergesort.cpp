#include <iostream>

void mergeSort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);
int count;

int main(void)
{
    int n;
    int arr[10005] = { 0, };

    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    mergeSort(arr, 0, n-1);
    std::cout << count << '\n';
    
    return 0;
}

void mergeSort(int arr[], int p, int r)
{
    if (p >= r)
        return;

    int q = (p+r) / 2;
    mergeSort(arr, p, q);
    mergeSort(arr, q+1, r);
    merge(arr, p, q, r);
}

void merge(int arr[], int p, int q, const int r)
{
    int temp[r];

    int i = p, j = q+1, t = 0;
    while (i <= q && j <= r)
    {
        temp[t++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
        count++;
    }

    while (i <= q) temp[t++] = arr[i++];
    while (j <= r) temp[t++] = arr[j++];

    i = p; t = 0;
    while (i <= r) arr[i++] = temp[t++];
}