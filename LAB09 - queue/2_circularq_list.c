#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert(int d)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = d;
    new->next = NULL;
    if ((front == NULL) && (rear == NULL))
    {
        front = rear = new;
        rear->next = front;
    }
    else
    {
        rear->next = new;
        rear = new;
        new->next = front;
    }
}

void delete()
{
    struct node *del;
    del = front;
    if ((front == NULL) && (rear == NULL))
        printf("\nThe queue is empty. \n");
    else if (front == rear)
    {
        front = rear = NULL;
        free(del);
        printf ("The deleted element is: %d", del->data);
    }
    else
    {
        front = front->next;
        rear->next = front;
        free(del);
        printf ("The deleted element is: %d", del->data);
    }
}

void display()
{
    struct node *tmp;
    tmp = front;
    if ((front == NULL) && (rear == NULL))
        printf("\nQueue is empty. \n");
    else
    {
        do
        {
            printf("%d ", tmp->data);
            tmp = tmp->next;
        } while (tmp != front);
    }
}

int main()
{
    int choice, n, d;
    while (1)
    {
        printf("\n1. insert\t2. delete\n3.display\t4. quit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of elements: \n");
            scanf("%d\n", &n);
            for (int i=0; i<n; i++)
            {
                printf ("Enter the data: ");
                scanf ("%d ", &d);
                insert(d);
            }
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Invalid input.");
            break;
        }
    }
}