#include <stdio.h>

int main()
{
    int n, i, r, arr[30];
    int count = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the item to be searched: ");
    scanf("%d", &r);
    for (int i = 0; i < n; i++)
    {
        if (r == arr[i])
            count++;
    }
    if (count == 0)
        printf("Element not found.");
    else
        printf("The frequency of the given element is %d", count);
    return 0;
}