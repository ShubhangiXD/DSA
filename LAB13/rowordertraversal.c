#include <stdio.h>
#define MAX 100

int main()
{
    printf("Enter the number of rows and columns: \n");
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n];

    printf("Enter the array elements: "); //!
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("The entered matric is: \n"); //!
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i < m; i++) //!!
    {
        for (int j = 1; j < n; j++)
        {
            int temp = arr[i][j];
            if (temp > arr[i - 1][j - 1])
            {
                free(arr[i][j]);
                if (i == m - 1 && j == n - 1)
                    arr[i][j] = 0;
                else
                    arr[i][j] = arr[i + 1][j + 1];
            }
        }
    }

    printf("The modified matrix is: \n");
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}