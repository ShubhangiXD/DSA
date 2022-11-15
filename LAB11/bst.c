//construct a bstree 10 11 40 48 32 5 7  count the number of nodes in the left and right subtree
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *lchild;
    int info;
    struct node *rchild;
} *root = NULL;

struct node *insert(struct node *ptr, int info) //making the bstree
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

struct node *leftsub(struct node *root, int key)
{
    if (root==NULL)
    return 0;
    while ()
}