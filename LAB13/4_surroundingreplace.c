/*Let a 2-dimensional matrix of size m X n contains elements either 0 or 1. 
WAP to replace an element 0 with 1, if all its surrounding elements are 1.*/
#include <stdio.h>

int main()
{
    int m, n, c = 0;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &m, &n);
    int a[m][n], b[m * n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            b[c++] = a[i][j];
        }
    }
    for (int i = 1; i < c; i++)
    {
        if (b[i + 1] == 1 && b[i - 1] == 1)
        {
            b[i] = 1;
        }
    }
    c = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = b[c++];
        }
    }
    printf("\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}