#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define size 5
// implementation of circular queue
int queue[size];
int front = -1; // initially no element is present in the queue
int rear = -1;  // initially no element is present in the queue

int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == size - 1))
        return 1;
    return 0;
}
int isEmpty()
{
    if (front == -1 && rear == -1)
        return 1;
    return 0;
}
void enQueue(int data)
{
    if (isFull())
    {
        printf("Overflow! Queue is full\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % size;
        queue[rear] = data;
        printf("Inserted -> %d", data);
    }
}
int deQueue()
{
    int x;
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        x = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
        printf("Deleted Element -> %d\n", x);
        return x;
    }
}
void display()
{
    int i;
    if (isEmpty())
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        for (i = front; i != rear; i = (i + 1) % size)
        {
            printf("%d ", queue[i]);
        }
        printf("%d", queue[i]);
    }
}
void peak()
{
    printf("\nPEAK-->%d", queue[front]);
}
int main()
{
    int ch;
    int elem;
    while (1)
    {
        printf("\nMenu:\n1.Enqueue \n2.Dequeue \n3.Display \n4.Peak \n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &elem);
            enQueue(elem);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            peak();
            break;
        case 5:
            printf("Exiting...");
            exit(0);
            break;
        default:
            printf("Invalid Choice..!");
            break;
        }
    }
}