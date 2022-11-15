#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int circ_check(struct node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    struct node *ptr;
    ptr = head->next;
    while (ptr != NULL && ptr != head)
    {
        ptr = ptr->next;
    }
    return (ptr == head);
}

struct node *new (int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next =NULL;
    return temp;
}

int main()
{
    struct node* head = new(1);
    head->next = new(2);
    head->next->next = new(3);
    head->next->next->next = new(4);

    if (circ_check(head))
    printf ("Circular");
    else
    printf("Null");
}