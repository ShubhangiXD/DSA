#include <stdio.h>
int main()
{
    int n;
    printf("Enter the order of matrix = ");
    scanf("%d", &n);
    int a[n][n], t[n][n], r[n][n], i, j, count = 0;
    printf("Enter elements for the Array\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("\n\nOriginal Array\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d  ", a[i][j]);
            t[i][j] = a[j][i];
            r[i][j] = a[i][j] + t[i][j];
            if (r[i][j] != 0)
                count++;
        }
        printf("\n");
    }
    printf("\n\nTranspose Array\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d  ", t[i][j]);
        printf("\n");
    }
    printf("\n\nSummation Array\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d  ", r[i][j]);
        printf("\n");
    }
    int tup[count + 1][3], k = 1;
    tup[0][0] = n;
    tup[0][1] = n;
    tup[0][2] = count;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (r[i][j] != 0)
            {
                tup[k][0] = i;
                tup[k][1] = j;
                tup[k][2] = r[i][j];
                k++;
            }
    printf("\n\nTriplet Representation\n\n");
    for (i = 0; i <= count; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d  ", tup[i][j]);
        printf("\n");
    }
    return 0;
}