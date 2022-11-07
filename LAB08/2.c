#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;

void create(){
    struct node *p;
    int data;
    printf("\nEnter data: ");
    scanf("%d",&data);
    p=malloc(sizeof(struct node));
    p->data=data;
    p->link=NULL;
    if (front==NULL)
    {
        front=p;
    }else{
        rear->link=p;
    }
    rear=p;
}
void display(){
    struct node *p;
    p=front;
    if (front==NULL)
    {
        printf("No element is available");
        return;
    }
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->link;
    }
}
void delete(){
    struct node *p;
    if (front==NULL)
    {
        printf("\nUnderflow");
        return;
    }
    p=front;
    printf("\nThe deleted element is %d",p->data);
    front=front->link;
    free(p);
}

int main()
{
    while (1)
    {
        int n;
        printf("\nEnter your choice: ");
        printf("\n1. create\t2. display\n3. delete\t4. exit\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            delete();
            break;
        case 4:
            exit(1);
        default:
            printf("\nInvalid choice");
            break;
        }
    }
    return 0;
}

