#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int front = -1, rear = -1;
int circq[SIZE];

void insert()
{
    int data;
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Overflow!");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
        rear++;
    printf("Enter the data: ");
    scanf("%d", &data);
    circq[rear] = data;
}

void delete ()
{
    if (front == -1)
    {
        printf("\nUnderflow!");
        return;
    }
    printf("The deleted element is %d.", circq[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == SIZE - 1)
            front = 0;
        else
            front++;
    }
}

void display()
{
    int f_pos = front;
    int r_pos = rear;
    if (f_pos <= r_pos)
        while (f_pos <= r_pos)
        {
            printf("%d ", circq[f_pos]);
            f_pos++;
        }

    else
    {
        while (f_pos <= SIZE - 1)
        {
            printf("%d ", circq[f_pos]);
            f_pos++;
        }
        f_pos = 0;
        while (f_pos <= r_pos)
        {
            printf("%d ", circq[f_pos]);
            f_pos++;
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. insert\t2. delete\n3.display\t4. quit\n\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
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
