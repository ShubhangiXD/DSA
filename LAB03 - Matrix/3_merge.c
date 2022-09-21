#include <stdio.h>
int main()
{
    int n1, n2, temp;
    printf("Enter size of 1st array : ");
    scanf("%d", &n1);
    printf("Enter size of 2nd array : ");
    scanf("%d", &n2);
    int arr1[n1], arr2[n1 + n2];

    printf("Enter elements for 1st array: ");
    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter elements for 2nd array: ");
    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    for (int i = 0; i < n1; i++)
        arr2[n2 + i] = arr1[i];

    for (int i = 0; i < n1 + n2 - 1; i++)
    {
        for (int j = 0; j < n1 + n2 - 1; j++)
        {
            if (arr2[j] > arr2[j + 1])
            {
                temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    printf("The merged array is: \n");
    for (int i = 0; i < (n1 + n2); i++)
        printf("%d ", arr2[i]);
}