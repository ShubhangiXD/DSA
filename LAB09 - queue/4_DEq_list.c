#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    struct node *prev;
    int data;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *create(int data)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = new->prev = NULL;
    return (new);
}

void def_value()
{
    front = create(0);
    rear = create(0);
    front->next = rear;
    rear->prev = front;
}

void insert_front(int d)
{
    struct node *new, *tmp;
    new = create(d);
    if (front == NULL)
        rear = front = new;
    else
    {
        tmp = front->next;
        front->next = new;
        new->prev = front;
        new->next = tmp;
        tmp->prev = new;
    }
}

void insert_rear(int d)
{
    struct node *new, *tmp;
    new = create(d);
    tmp = rear->prev;
    rear->prev = new;
    new->next = rear;
    new->prev = tmp;
    tmp->next = new;
}

void delete_front()
{
    struct node *temp;
    if (front->next == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = front->next;
        front->next = temp->next;
        temp->next->prev = front;
        free(temp);
    }
    return;
}

void delete_rear()
{
    struct node *temp;
    if (rear->prev == front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = rear->prev;
        rear->prev = temp->prev;
        temp->prev->next = rear;
        free(temp);
    }
    return;
}

void display()
{
    struct node *temp;

    if (front->next == rear)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front->next;
    while (temp != rear)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int data, ch;
    while (1)
    {
        printf("1. Insert at front\n2. Insert at rear\n");
        printf("3. Delete at front\n4. Delete at rear\n");
        printf("5. Display\n6. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data to insert:");
            scanf("%d", &data);
            insert_front(data);
            break;

        case 2:
            printf("Enter data to insert:");
            scanf("%d", &data);
            insert_rear(data);
            break;

        case 3:
            delete_front();
            break;

        case 4:
            delete_rear();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid output.\n");
            break;
        }
    }
    return 0;
}
