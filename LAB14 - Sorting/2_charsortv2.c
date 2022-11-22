#include <stdio.h>
#define MAX 20

void sort(char arr[], int n)
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

void input(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter element among x, y, z for idx %d: ", i + 1);
        fflush(stdin);
        scanf("%c", &arr[i]);
    }
}

void print(char arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main()
{
    char arr[MAX];
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    arr[n];
    input(arr, n);
    sort(arr, n);
    printf("Sorted array: ");
    print(arr, n);
    return 0;
}
