#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create_List()
{
    struct Node *pointer = NULL;
    int length;
    printf("Enter the length of the list: \n");
    scanf("%d", &length);
    struct Node *new, *temp;
    for (int i = 0; i < length; i++)
    {
        new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter the element %d \n", i + 1);
        scanf("%d", &new->data);

        new->next = NULL;
        if (pointer == NULL)
            pointer = temp = new;
        else
        {
            temp->next = new;
            temp = new;
        }
    }
    return pointer;
}

void display_List(struct Node *head)
{
    printf("Your list is: \n");
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    temp = head;
    printf("\n\n");
}

struct Node *insert_beg(struct Node *head)
{
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("**INSERTION AT BEGINNING**\n");
    printf("Enter the value you want to insert:");
    scanf("%d", &new->data);
    new->next = head;
    head = new;
    printf("The list after inserting a Node in the beginning is:\n");
    return head;
}

struct Node *insert_end(struct Node *head)
{
    struct Node *temp, *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    printf("**INSERTION AT END**\n");
    printf("Enter the value you want to insert:");
    scanf("%d", &new->data);
    new->next = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;

    return head;
}

void count(struct Node *head)
{
    struct Node *ptr;
    head = ptr;

    int count = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        count++;
    }

    ptr = head;
    printf("Length of list is:%d\n", count);
}

struct Node *insert_any(struct Node *head)
{
    struct Node *next, *temp;
    int pos, count = 0, i;
    printf("Enter the position:");
    scanf("%d", &pos);
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    temp = head;

    if (pos > count || pos < 0)
    {
        printf("INVALID POSITION!\n");
    }
    else if (pos == 0)
    {

        struct Node *new;
        new = (struct Node *)malloc(sizeof(struct Node));
        printf("**INSERTION AT BEG**\n");
        printf("Enter the value you want to insert:");
        scanf("%d", &new->data);
        new->next = head;
        head = new;
        return head;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        struct Node *new;
        new = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data:");
        scanf("%d", &new->data);

        new->next = temp->next;
        temp->next = new;
    }

    return head;
}

void search(struct Node *head)
{
    int val, count = 0, i = 1;
    printf("Enter data to search:");
    scanf("%d", &val);
    struct Node *temp;
    temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    temp = head;

    if (val == head->data)
    {
        printf("Element position 1\n");
    }
    else
    {
        while (temp->data != val)
        {
            temp = temp->next;
            i++;
        }

        printf("Element position %d\n", i);
    }
}

int main()
{
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    int choice;
    printf("****MENU****\n");

    while (1)
    {
        printf("1.Create a linked list.\n2.Display the list.\n3.Insert element at beginning.\n4.Insert at end.\n5.Insert at any position.\n6.Search an element.\n7.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            list1 = create(list1);
            break;
            ;

        case 2:
            display(list1);
            break;

        case 3:
            list1 = insert_beg(list1);
            break;

        case 4:
            list1 = insert_END(list1);
            break;

        case 5:
            list1 = insert_any(list1);
            break;

        case 6:
            search(list1);
            break;

        case 7:
            exit(0);
        }
    }

    return 0;
}