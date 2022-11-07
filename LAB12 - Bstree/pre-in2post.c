#include <stdio.h>

int search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void printPostOrder(int in[], int pre[], int n)
{
    int root = search(in, pre[0], n);
 
    if (root != 0)
        printPostOrder(in, pre + 1, root);
 
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
 
    printf("%d ", pre[0]);
}

int main()
{
    int in[] = { 1, 2, 3, 4, 5, 6 };
    int pre[] = {4, 2, 1, 3, 5, 6 };
    int n = sizeof(in) / sizeof(in[0]);
    printf ("Postorder traversal: \n");
    printPostOrder(in, pre, n);
    return 0;
}