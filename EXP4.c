#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>
#define size 10
// linear queue implementation
int front = -1, rear = -1;
struct bill
{
    int item_id;
    float amt, quantity;
    char name[50];
} b[size];
void enqueue()
{
    if (rear == size - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        printf("\nEnter item id:");
        scanf("%d", &b[rear].item_id);
        printf("Enter amount:");
        scanf("%f", &b[rear].amt);
        printf("Enter Name:");
        scanf("%s",b[rear].name);
        printf("Enter quantity:");
        scanf("%f", &b[rear].quantity);
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("\nDeleting %d, %s , RS. %.3f , %.3f\n", b[front].item_id, b[front].name, b[front].amt, b[front].quantity);
        front++;
    }
}
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("\nItem ID:%d \nAmount:%.2f \nName:%s \nQuantity:%.0f ", b[i].item_id, b[i].amt, b[i].name, b[i].quantity);
        }
    }
}
float out()
{
    float total = 0;
    for (int j = front; front <= rear; j++)
    {
        total += b[j].quantity * b[j].amt;
    }
    return total;
}
int main()
{
    int ch;
    printf("\nMENU:\n");
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    while (1)
    {
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            float result=out();
            printf("\nBill Amount: %.2f\t", result);
            exit(0);
            break;
        default:
            printf("\nInvalid Choice!!!\n");
            break;
        }
    }
    return 0;
}