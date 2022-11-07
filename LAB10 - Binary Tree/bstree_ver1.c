#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
} *root = NULL;

struct node *insert(struct node *ptr, int key)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = key;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if (key < ptr->info)
    {
        ptr->lchild = insert(ptr->lchild, key);
    }
    else if (key > ptr->info)
    {
        ptr->rchild = insert(ptr->rchild, key);
    }
    else
    {
        printf("Duplicated key node.");
    }
    return ptr;
}

void PreOrder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d", ptr->info);
    PreOrder(ptr->lchild);
    PreOrder(ptr->rchild);
}

void PostOrder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    PostOrder(ptr->lchild);
    PostOrder(ptr->rchild);
    printf("%d", ptr->info);
}

void InOrder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    InOrder(ptr->lchild);
    printf("%d", ptr->info);
    InOrder(ptr->rchild);
}
void main()
{
    struct node *root = NULL, *ptr;
    int choice, k;
    printf("Enter your choice: \n");
    while (1)
    {
        printf("\n1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal \n5. Exit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter node value: ");
            scanf("%d", &k);
            root = insert(root, k);
            break;

        case 2:
            printf("\nPre-order traversal of the given nodes is: \n");
            PreOrder(root);
            break;

        case 3:
            printf("\nIn-order traversal of the given nodes is: \n");
            InOrder(root);
            break;

        case 4:
            printf("\nPost-order traversal of the given nodes is: \n");
            PostOrder(root);
            break;

        case 5:
            printf("\nExiting.");
            exit(1);

        default:
            printf("Wrong Choice!");
        }
    }
}