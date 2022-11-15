// input: 12: 48, 44, 19, 59, 72, 80, 42, 65, 82, 08, 95, 68. <<store in an array>>
// pivot is at 48, find i and j. Use quick sort
//! the program has an error, do not refer to this program
//TODO correct the program


#include <stdio.h>

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick(arr, low, pi - 1);
        quick(arr, pi + 1, high);
    }
}

void display(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {48, 44, 19, 59, 72, 80, 42, 65, 82, 8, 95, 68};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick(arr, 0, n - 1);
    printf("Sorted array: \n");
    display(arr, n);
    return 0;
}