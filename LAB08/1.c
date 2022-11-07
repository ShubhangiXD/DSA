#include<stdio.h>
#include<stdlib.h>
int a[10],front,rear;
void push(){
    int data;
    if(rear==9){
        printf("\nOverflow");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d",&data);
    a[++rear]=data;
    if (front==-1)
    {
        front=0;
    }
}
void display(){
    if (front==-1||front>rear)
    {
        printf("Underflow");
        return;
    }
    for (int i = front; i <=rear; i++)
    {
        printf("%d ",a[i]);
    }
}
void delete(){
    if (front==-1||front>rear)
    {
        printf("\nNo element is available");
        return;
    }
    printf("The deleted element is %d",a[front]);
    front++;
}
int main()
{
    front=rear=-1;
    int n;
    while (1)
    {
        printf("\nEnter your choice: ");
        printf("\n1. create\t2. display\n3. delete\t4. exit\n");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            push();
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

