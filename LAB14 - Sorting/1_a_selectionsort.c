// implement selection sort
#include <stdio.h>
#define MAX 100

void selection(int arr[], int n) //pseudocode for selection sort
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min])
                min = j;

        if (min != i)
        {
            int t = arr[min];
            arr[min] = arr[i];
            arr[i] = t;
        }
    }
}

void input(int arr[], int n)
{
    for (int i=0; i<n; i++)
    {
        printf ("Enter element %d: ", i+1);
        scanf ("%d", &arr[i]);
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
    printf ("Enter the number of elements of the array: ");
    scanf("%d", &n);
    arr[n];
    input(arr, n);
    selection(arr, n);
    printf("Sorted array: ");
    print(arr, n);
    return 0;
}