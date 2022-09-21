#include <stdio.h>
void array_union(int a[10], int m, int b[10], int n, int u[10])
{
    int i, c, j, k;
    for (i = 0; i < m; i++)
    {
        u[i] = a[i];
    }
    j = i;
    for (i = 0; i < n; i++)
    {
        c = 0;
        for (k = 0; k < j - 1; k++)
        {
            if (b[i] == u[k])
                c++;
        }
        if (c == 0)
            u[j++] = b[i];
    }
    printf("\nThe union of two arrays is: ");

    for (i = 0; i < j; i++)

        printf("%d ", u[i]);
}
void array_intersection(int a[10], int m, int b[10], int n, int in[10])
{
    int i, j, c, k = 0;
    for (i = 0; i < m; i++)
    {
        c = 0;
        for (j = 0; j < n; j++)
        {

            if (a[i] == b[j])

                c++;
        }
        if (c != 0)
        {

            in[k++] = a[i];
        }
    }
    printf("\nThe intersection of two arrays is: ");

    for (i = 0; i < k; i++)

        printf("%d ", in[i]);
}
int main()
{
    int n1, n2, i, j, u[10];
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    int array1[n1];
    for (int i = 0; i < n1; ++i)
    {
        printf("Enter the elements in the first array: ");
        scanf("%d", &array1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    int array2[n2];
    for (int i = 0; i < n2; ++i)
    {
        printf("Enter the elements in the second array: ");
        scanf("%d", &array2[i]);
    }

    for (i = 0; i < n1; i++)
    {
        printf("Array 1: ", "%d ", array1[i]);
    }
    printf("\n");
    for (i = 0; i < n2; i++)
    {
        printf("Array 2: ", "%d ", array2[i]);
    }

    array_union(array1, n1, array2, n2, u);
    array_intersection(array1, n1, array2, n2, u);
    return 0;
}