#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++ )
    {
        scanf("%d", &a[i]);
    }
        
    printf("\nThe elements of the array in reverse order:\n");
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);
    return 0;
}