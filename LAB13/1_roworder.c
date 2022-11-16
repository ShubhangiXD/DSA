/*Traverse a m X n matrix in row major order. During traversing, if the current traversed element is greater 
than the previously traversed element, then delete the current element and shift the remaining elements of the 
matrix. The last blank place should be filled with zero.*/
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
        while (b[i] > b[i - 1])
        {
            for (int j = i; j < c - 1; j++)
            {
                int temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
            b[c - 1] = 0;
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