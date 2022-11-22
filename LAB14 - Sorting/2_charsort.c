#include <stdio.h>
#define MAX 20

void sort(char arr[], int n)
{
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'x' || arr[i] == 'X')
            arr2[i] = 1;
        else if (arr[i] == 'y' || arr[i] == 'Y')
            arr2[i] = 2;
        else if (arr[i] == 'z' || arr[i] == 'Z')
            arr2[i] = 3;
    }

    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (arr2[j] < arr2[min])
                min = j;

        if (min != i)
        {
            int t = arr[min];
            arr[min] = arr[i];
            arr[i] = t;

            int t1 = arr2[min];
            arr2[min] = arr2[i];
            arr2[i] = t1;
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
