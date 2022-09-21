#include <stdio.h>
void main()
{
    int l1, l2;
    int arr1[l1], arr2[l2];
    printf("Enter the number of elements in the first array: \n");
    scanf("%d", &l1);
    printf("Enter the elements of the first array: \n");
    for (int i = 0; i < l1; i++)
    {
        printf("Enter element %d", i + 1);
        scanf("%d", arr1[i]);
    }
    printf("Enter the number of elements in the second array: \n");
    scanf("%d", &l2);
    printf("Enter the elements of the second array: \n");
    for (int i = 0; i < l2; i++)
    {
        printf("Enter element %d", i + 1);
        scanf("%d", arr2[i]);
    }

    int x;
    printf("Enter the value to be computed. \n");
    scanf("%d", &x);
    int t=0;

    for (int i = 0; i < l1; i++)
    {
        for (int j = 0; j < l2; j++)
        {
            if (arr1[i] + arr2[j] == x)
            {
                printf("The element pairing that equals to %d is: {%d , %d}", x, arr1[i], arr2[j]);
                t++;
            }
            else
                continue;
        }
    }
    if (t==0)
    printf ("No pairings give %d as a sum.", x);
}