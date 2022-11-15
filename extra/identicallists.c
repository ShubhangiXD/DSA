#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int key;
    struct node *next;
};

int if_iden(struct node *list1, struct node *list2)
{
    while (list1!=NULL && list2!=NULL)
    {
        if (list1->key!= list2->key)
        return 0;

        else
        list1=list1->next;
        list2=list2->next;
    }
    return (list1==NULL && list2==NULL);
}

void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node
        = (struct Node*)malloc(sizeof(struct Node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list of the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

