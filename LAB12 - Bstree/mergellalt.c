#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **head_ptr, int key)
{
    struct node *new = malloc(sizeof(struct node));
    new->data = key;
    new->next = (*head_ptr);
    (*head_ptr) = new;
}

void display(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void merge(struct node *p, struct node **q)
{
    struct node *p_c = p, *q_c = *q;
    struct node *p_n, *q_n;
    while (p_c != NULL && q_c != NULL)
    {
        p_n = p_c->next;
        q_n = q_c->next;

        q_c->next = p_n;
        p_c->next = q_c;

        p_c = p_n;
        q_c = q_n;
    }
    *q = q_c;
}

int main()
{
    struct node *p = NULL, *q = NULL;
    while (1)
    {
        printf("Enter 1 to create the first linked list, 2 to create the second, 3 to merge and exit. \n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the length of the list: \n");
            int l1;
            scanf("%d, &l1");
            for (int i = 0; i < l1; i++)
            {
                printf("Enter the node value: \n");
                int d;
                insert(&p, d);
            }
            break;

        case 2:
            printf("Enter the length of the list: \n");
            int l2;
            scanf("%d, &l2");
            for (int i = 0; i < l2; i++)
            {
                printf("Enter the node value: \n");
                int d;
                insert(&q, d);
            }
            break;

        case 3:
            printf("The list after merging is: \n");
            merge(p, &q);
            printf("First list after modification: \n");
            display(p);
            printf("Second list after modification: \n");
            display(q);
            exit(1);

        default:
            printf("Wrong input. \n");
        }
    }
    return 0;
}