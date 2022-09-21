#include <stdio.h> //merge and sort the array in ascending order
void sort(int a[], int);
void main()
{
    int a[20], c[10], i, m, n, j;
    printf("Enter the no. of elements in 1st array \n");
    scanf("%d", &m);
    printf("Enter the 1st array: \n");
    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);
    printf("Enter the no.of elements in the 2nd array \n");
    scanf("%d", &n);
    printf("Enter the 2nd array: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &c[i]);
    sort(a, m);
    printf("1st sorted array - \n");
    for (i = 0; i < m; i++)
        printf("%d ", a[i]);
    sort(c, n);
    printf("\n");
    printf("2nd sorted array - \n");
    for (i = 0; i < n; i++)
        printf("%d ", c[i]);
    j = m;
    for (i = 0; i < n; i++)
    {
        a[j] = c[i];
        j++;
    }
    sort(a, m + n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                for (int k = j; k < n - 1; k++)
                {
                    a[k] = a[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    printf("Merged and Sorted array - \n");
    for (i = 0; i < m + n; i++)
        printf("%d ", a[i]);
}

void sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    }
}