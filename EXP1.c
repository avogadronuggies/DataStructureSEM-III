#include <stdio.h>
#include <stdlib.h>
#define size 5
struct box
{
    char colour[10];
    int height;
    int width;
    
};
struct box b[size];
int top=-1;
void push(struct box item)
{
    if(top==size-1)
    {
        printf("Stack Overflow\n");
    }
    else{
        top++;
        b[top]=item;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
    }
    else{
        printf("Deleting %s %d %d",b[top].colour,b[top].height,b[top].width);
    }
}

void peek()
{
    printf("TOP Element: %s %d %d",b[top].colour,b[top].height,b[top].width);
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