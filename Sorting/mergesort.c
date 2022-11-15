#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    int l1, l2;
    int arr1[l1];
    int arr2[l2];
    int arr3[l1 + l2];
    printf("Enter the length of the first array: \n");
    scanf("%d", &l1);
    printf("Enter the length of the second array: \n");
    scanf("%d", &l2);
    int min, max;
    if (l1 > l2)
    {
        min = l1;
        max = l2;
    }
    else
    {
        min = l2;
        max = l1;
    }
    for (int i = 0; i < l1 + l2;)
    {
        for (int j = 0; j <= i;)
        {
            if (arr1[i] < arr2[j])
            {
                arr3[i] = arr1[i];
                i++;
            }
            else if (arr1[i] < arr2[j])
            {
                arr3[i] = arr2[j];
                j++;
            }
            else
            {
                arr3[i] = arr2[i];
                i++;
                j++;
            }
        }
    }

    printf("The merged and sorted list is: \n");
    for (int i = 0; i < l1 + l2; i++)
        printf("%d ", arr3[i]);
    return 0;
}

