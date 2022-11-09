#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
} *root = NULL;

struct node *insert(struct node *ptr, int info)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = info;
        ptr->lchild = NULL;
        ptr->rchild = NULL;
    }
    else if (info < ptr->info)
    {
        ptr->lchild = insert(ptr->lchild, info);
    }
    else if (info > ptr->info)
    {
        ptr->rchild = insert(ptr->rchild, info);
    }
    else
    {
        printf("Duplicated info node.");
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

struct node *minnode(struct node *node)
{
    struct node *current = node;

    while (current && current->lchild != NULL)
        current = current->lchild;

    return current;
}

struct node *deletenode(struct node *root, int info)
{
    if (root == NULL)
        return root;

    if (info < root->info)
        root->lchild = deletenode(root->lchild, info);

    else if (info > root->info)
        root->rchild = deletenode(root->rchild, info);

    else
    {

        if (root->lchild == NULL)
        {
            struct node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            struct node *temp = root->lchild;
            free(root);
            return temp;
        }

        struct node *temp = minnode(root->rchild);

        root->info = temp->info;
        root->rchild = deletenode(root->rchild, temp->info);
    }
    return root;
}

int search(struct node *root, int value)
{
    while (root != NULL)
    {

        if (value > root->info)
            root = root->rchild;

        else if (value < root->info)
            root = root->lchild;
        else
            return 1;
    }
    return 0;
}

int main()
{
    struct node *root = NULL, *ptr;
    int choice, k;
    printf("Enter your choice: \n");
    while (1)
    {
        printf("\n1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal \n5. Delete a node \n6. Search a node \n7. Exit\n\n");
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
            printf("Enter the value to be deleted. \n");
            int del;
            scanf("%d", &del);
            deletenode(root, del);
            break;

        case 6:
            printf("Enter the value to be searched: \n");
            int ser;
            scanf("%d", &ser);
            if (search(root, ser)==1)
            printf("The node was found in the tree.\n");
            else
            printf ("The node is not found.\n");
            break;

        case 7:
            printf("\nExiting.");
            exit(1);

        default:
            printf("Wrong Choice!");
        }
    }
    return 0;
}