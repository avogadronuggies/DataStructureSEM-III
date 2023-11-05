#include <stdio.h>
#include <stdlib.h>
#include<string.h>
// Implement Stack ADT using Linked List
struct Node
{
    int pages;
    char bookName[50];
    int price;
    struct Node* next;
};
struct Node *head = NULL;
void push()
{
    int price, pages;
    char name[50];
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("OVERFLOW\n");
    }
    else
    {
        printf("\nEnter Book Name: ");
        scanf("%s", name);
        strcpy(temp->bookName, name);
        printf("\nEnter Pages of the Book: ");
        scanf("%d", &pages);
        temp->pages=pages;
        printf("\nEnter Price of the Book: ");
        scanf("%d", &price);
        temp->price=price;
        temp->next = head;
        head = temp;
        printf("Element Inserted Successfully\n");
    }
}
void pop()
{
    struct Node* ptr;
    if (head == NULL)
    {
        printf("UNDEFLOW\n");
    }
    else
    {
        ptr = head;
        head = head->next;
        free(ptr);
        printf("Element Deleted Successfully\n");
    }
}
void peek()
{
    if (head == NULL)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Book Name : %s \n", head->bookName);
        printf("Pages : %d \n", head->pages);
        printf("Price : %d \n", head->price);
    }
}
void display()
{
    struct Node* temp = head;
    printf("\nSTACK\n");
    while (temp != NULL)
    {
        printf("Book Name : %s \n", temp->bookName);
        printf("Pages : %d \n", temp->pages);
        printf("Price : %d \n", temp->price);
        printf("\n");
        temp = temp->next;
    }
}
int main()
{
    int ch;
    do
    {
        printf("BOOK STACK OPERATIONS\n");
        printf("\t1. PUSH\n");
        printf("\t2. POP\n");
        printf("\t3. DELETE TOP ELEMENT\n");
        printf("\t4. DISPLAY ALL BOOKS IN THE STACK\n");
        printf("\t5.Exit\n");
        printf("\tEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
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
            exit(0);
            break;
            default:
            printf("\nInvalid Choice\n");
            break;
        }
        }while(1);
}