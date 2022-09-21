#include <stdio.h>
void main()
{
    int n;
    printf("Enter the array of elements.\n");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int d;
        printf("Enter element %d of the array: ", i + 1);
        scanf("%d", &d);
        arr[i] = d;
        d = 0;
    }
    printf("The elements of the array are: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
    int store;
    for (int i = 0; i < n; ++i)
    {

        for (int j = i + 1; j < n; ++j)
        {

            if (arr[i] > arr[j])
            {

                store = arr[i];
                arr[i] = arr[j];
                arr[j] = store;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n - 1; k++)
                {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    printf("The elements which have at least two smaller elements are: \n");
    for (int i = 2; i < n; i++)
    {
        printf("%d \n", arr[i]);
    }
}