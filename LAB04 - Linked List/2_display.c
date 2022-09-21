#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void printList()
{
    if (head == NULL)
        printf("The stack is empty. \n");
    else
    {
        printf("The list is: \n");
        struct node *tmp = head;
        while (tmp->next != NULL)
        {
            printf("%d ----->", tmp->data);
            tmp = tmp->next;
        }
        printf("%d----->NULL", tmp->data);
    }
}

void create_list()
{
    int n;
    printf("Enter the number of node: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        struct node *new;
        new = (struct node *)malloc(sizeof(struct node));
        int val;
        printf("Enter the value for node %d", i + 1);
        scanf("%d", &val);
        new->data = val;

        if (head == NULL)
            new->next = NULL;
        else
            new->next = head;
        head = new;
        printf("The node is inserted. \n");
    }
}
int main()
{
    create_list();
    printList();
    return 0;
}