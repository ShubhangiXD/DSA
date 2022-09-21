#include <stdio.h>
void findCommon(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2 && k < n3)
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            printf("%d ", arr1[i]);
            i++;
            j++;
            k++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr3[k])
            j++;
        else
            k++;
    }
}
int main()
{
    int n1;
    printf("enter the size of 1st array:");
    scanf("%d", &n1);

    int arr1[n1];
    printf("enter the elements for 1st array:");
    for (int i = 0; i < n1; i++)
        scanf("%d", &arr1[i]);

    int n2;
    printf("enter the size of 2nd array:");
    scanf("%d", &n2);

    int arr2[n2];
    printf("enter the elements for 2nd array:");
    for (int i = 0; i < n2; i++)
        scanf("%d", &arr2[i]);

    int n3;
    printf("enter the size of 3rd array:");
    scanf("%d", &n3);

    int arr3[n3];
    printf("enter the elements for 3rd array:");
    for (int i = 0; i < n3; i++)
        scanf("%d", &arr3[i]);

    printf("Common Elements are ");
    findCommon(arr1, arr2, arr3, n1, n2, n3);
    return 0;
}