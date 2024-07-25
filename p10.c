#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high); 
    }
}

int main()
{
    int n;
    printf("Enter a value of n greater than 4000\n");
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10000;
    }

    clock_t start, end;
    double time_used;
    start = clock();
    quickSort(a, 0, n - 1);
    end = clock();
    time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("%f\n", time_used);

    return 0;
}
