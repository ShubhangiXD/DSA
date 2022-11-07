// construct a binary search tree from a given preorder traversal
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *L_child;
    struct node *R_child;
};
struct node *root = NULL; // taking initial root as NULL as there is no current value and it keeps changing depending on the tree/subtree

// function to crate a node
struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->L_child = temp->R_child = NULL;
    return temp;
}

// function to create a tree
struct node *construct_tree(int pre[], int *pre_ind, int low, int high, int size)
{
    if (*pre_ind >= size || low > high)
        return NULL;

    struct node *root = newNode(pre[*pre_ind]);
    *pre_ind = *pre_ind + 1;

    if (low == high)
        return root;

    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data)
            break;
    
    root->L_child=construct_tree(pre, pre_ind, *pre_ind, i-1, size);
    root->R_child=construct_tree(pre, pre_ind, i, high, size);

    return root;
}

struct node* construct(int pre[], int size)
{
    int pre_ind = 0;
    return construct_tree(pre, &pre_ind, 0, size-1, size);
}

void print_inorder(struct node* node)
{

}