// implement insertion sort
#include <stdio.h>
#define MAX 50

void insertion(int arr[], int n)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void input(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[MAX];
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    arr[n];
    input(arr, n);
    insertion(arr, n);
    printf("Sorted array: ");
    print(arr, n);
    return 0;
}