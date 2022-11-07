#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *insert(struct node *ptr, int key)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = key;
        ptr->left = NULL;
        ptr->right = NULL;
    }
    else if (key < ptr->data)
    {
        ptr->left = insert(ptr->left, key);
    }
    else if (key > ptr->data)
    {
        ptr->right = insert(ptr->right, key);
    }
    else
    {
        printf("Duplicated key node.\n");
    }
    return ptr;
}   

int count(struct node *root, int low, int high)
{
    if (root == NULL)
        return 0;

    if (root->data <= high && root->data >= low)
    {
        return (1 + count(root->left, low, high) + count(root->right, low, high));
    }

    else if (root->data < low)
        return count(root->right, low, high);

    else
        return count(root->left, low, high);
}

int main()
{
    struct node *root = NULL;
    int choice, k;
    while (1)
    {
        printf("\nPress 1 to insert a node, 2 to count the number of nodes and exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter node value: ");
            scanf("%d", &k);
            root = insert(root, k);
            break;

        case 2:
            printf("Enter the low and high values: \n");
            int l, h;
            scanf("%d %d", &l, &h);
            printf("The number of nodes between %d and %d is %d", l, h, count(root, l, h));
            exit(1);

        default:
            printf("Wrong choice.");
        }
    }
    return 0;
}
