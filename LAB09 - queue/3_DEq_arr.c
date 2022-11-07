#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
int dq[SIZE];
int front, rear;

void display()
{
    int f_pos = front;
    int r_pos = rear;
    if (f_pos <= r_pos)
        while (f_pos <= r_pos)
        {
            printf("%d ", dq[f_pos]);
            f_pos++;
        }

    else
    {
        while (f_pos <= SIZE - 1)
        {
            printf("%d ", dq[f_pos]);
            f_pos++;
        }
        f_pos = 0;
        while (f_pos <= r_pos)
        {
            printf("%d ", dq[f_pos]);
            f_pos++;
        }
    }
}

void insert_front()
{
    int data;
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Overflow!\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
        front = front--;
    printf("Enter the data: ");
    scanf("%d", &data);
    dq[front] = data;
}

void insert_rear()
{
    int data;
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Overflow!\n");
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
    dq[rear] = data;
}

void delete_front()
{
    if (front == -1)
    {
        printf("\nUnderflow!");
        return;
    }
    printf("The deleted element is %d. \n", dq[front]);
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

void delete_rear()
{
    if (front == -1)
    {
        printf("\nUnderflow!");
        return;
    }
    printf("The deleted element is %d. \n", dq[rear]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (rear == 0)
            rear = SIZE - 1;
        else
            rear = rear - 1;
    }
}

void input_dq()
{
    int choice;
    while (1)
    {
        printf("\n1. insert at the rear\t2. delete at the front\n3. delete at the rear\t4. display\n5. quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_rear();
            break;
        case 2:
            delete_front();
            break;
        case 3:
            delete_rear();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid input.");
        }
    }
}

void output_dq()
{
    int choice;
    while (1)
    {
        printf("\n1. insert at the front\t2. insert at the rear\n3. delete at the front\t4. display\n5. quit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_front();
            break;
        case 2:
            insert_rear();
            break;
        case 3:
            delete_front();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid input.");
        }
    }
}

void main()
{
    int choice;
    printf("\n1. input restricted dq \t2. output restricted dq \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        input_dq();
        break;
    case 2:
        output_dq();
        break;
    default:
        printf("Wrong choice.");
    }
}