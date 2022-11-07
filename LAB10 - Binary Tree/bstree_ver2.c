#include <stdio.h>
#include <stdlib.h>
// version 2 has a delete function with three cases - the parent node has no/one or two children.
struct node
{
    struct node *l_child;
    int info;
    struct node *r_child;
} *root = NULL;

struct node *insert(struct node *ptr, int key)
{
    if (ptr == NULL)
    {
        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->info = key;
        ptr->l_child = NULL;
        ptr->r_child = NULL;
    }
    else if (key < ptr->info)
    {
        ptr->l_child = insert(ptr->l_child, key);
    }
    else if (key > ptr->info)
    {
        ptr->r_child = insert(ptr->r_child, key);
    }
    else
    {
        printf("Duplicated key node.");
    }
    return ptr;
}

struct node *case_1(struct node *root, struct node *parent, struct node *ptr) // has no child nodes
{
    if (parent == NULL)
        root = NULL;

    else if (ptr == parent->l_child)
        parent->l_child = NULL;
    else
        parent->r_child = NULL;

    free(ptr);
}

struct node *case_2(struct node *root, struct node *parent, struct node *ptr)
{
    struct node *child;

    if (ptr->l_child != NULL) // node to be deleted has a left child
        child = ptr->l_child;
    else
        child = ptr->r_child;

    if (parent == NULL)
        root = child;
    else if (ptr == parent->l_child)
        parent->l_child = child;
    else
        parent->r_child = child;
    free(ptr);
    return root;
}

struct node *case_3(struct node *root, struct node *parent, struct node *ptr)
{
    // if the leftmost node of the right subtree of node N(?)
    struct node *inorder_successor, *parent_successor;
    parent_successor = ptr;
    inorder_successor = ptr->r_child;
    while (inorder_successor->l_child != NULL)
    {
        parent_successor = inorder_successor;
        inorder_successor = inorder_successor->l_child;
    }
    ptr->info = inorder_successor->info;

    if (inorder_successor->l_child == NULL && inorder_successor->r_child == NULL)
        root = case_1(root, parent_successor, inorder_successor);
    else
        root = case_2(root, parent_successor, inorder_successor);

    return root;
}

struct node *delete (struct node *root, int key)
{
    struct node *parent, *ptr;
    ptr = root;
    parent = NULL;
    while (ptr != NULL)
    {
        if (key == ptr->info)
            break;
        parent = ptr;

        if (key < ptr->info)
            ptr = ptr->l_child;

        else
            ptr = ptr->r_child;
    }
    if (ptr == NULL)
        printf("The key is not present.\n");

    else if (ptr->l_child != NULL && ptr->r_child != NULL)
        root = case_3(root, parent, ptr);

    else if (ptr->l_child != NULL)
        root = case_2(root, parent, ptr);

    else if (ptr->r_child != NULL)
        root = case_2(root, parent, ptr);

    else
        root = case_1(root, parent, ptr);
    return root;
}


void PreOrder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    printf("%d", ptr->info);
    PreOrder(ptr->l_child);
    PreOrder(ptr->r_child);
}

void PostOrder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    PostOrder(ptr->l_child);
    PostOrder(ptr->r_child);
    printf("%d", ptr->info);
}

void InOrder(struct node *ptr)
{
    if (ptr == NULL)
        return;
    InOrder(ptr->l_child);
    printf("%d", ptr->info);
    InOrder(ptr->r_child);
}
void main()
{
    struct node *root = NULL, *ptr;
    int choice, k;
    printf("Enter your choice: \n");
    while (1)
    {
        printf("\n\n1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal \n5. Deletion of node\t6. Exit \n\n");
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
            printf("Enter the node to be deleted: \n");
            int *r;
            scanf("%d", r);
            printf("The tree after deleting the node is:");
            delete (root, r); 
            break;

        case 6:
            printf("\nExiting.");
            exit(1);

        default:
            printf("Wrong Choice!");
        }
    }
}