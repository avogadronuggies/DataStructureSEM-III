#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int arr[SIZE];
int top = -1;
// implementation of stack using array

// PUSH Function
void push()
{
    int data;
    printf("Enter the element to be pushed: ");
    scanf("%d", &data);
    if (top == -1)
    {
        printf("%d pushed onto the stack", data);
        top++;
        arr[top] = data;
    }
    else if (top == SIZE)
    {
        printf("Stack Overflow");
    }
    else
    {
        printf("%d pushed onto the stack", data);
        top++;
        arr[top] = data;
    }
}
//Deleting the element at the top of stack
void pop()
{
    if (top == -1)
    {
        printf("Stack underflow");
    }
    else
    {
        printf("Element Deleted from the stack %d",arr[top]);
        top--;
    }
}
//Display the element at the top of the stack
void peek()
{
    printf("The topmost element is %d\n", arr[top]);
}
//Display the stack elements
void display()
{
    print("TOP");
    print("|");
    print("v");
    for(int i=top;i>-1;i--)
    {
        printf("%d\n",arr[i]);
    }
}
int main()
{
    int choice;

    while (1)
    {
        printf("\nChoose Operation:\n");
        printf("1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(1);
            break;

        default:
            printf("WRONG CHOICE!!!!!!");
            break;
        }
    }
    return 0;
}