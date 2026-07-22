#include <iostream>

int partition(int arr[], int p, int r);
void quickSort(int arr[], int p, int r);
int count;

int main(void)
{
    int arr[10005] = { 0, };
    int n;

    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    quickSort(arr, 0, n-1);

    std::cout << count << '\n';

    return 0;
}

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p-1;
    int temp;

    for (int j = p; j < r; j++) 
    {
        if (arr[j] <= x)
        {
            temp = arr[++i];
            arr[i] = arr[j];
            arr[j] = temp;
            count++;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    count++;

    return i+1;
}

void quickSort(int arr[], int p, int r)
{
    if (p >= r)
        return;

    int q = partition(arr, p, r);
    quickSort(arr, p, q-1);
    quickSort(arr, q+1, r);
}