
#include <stdio.h>
#include <stdlib.h>

// Implementation of Singly Linked List
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the list
struct Node *insertatBeginning(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    newNode->next = head;
    return newNode;
}

// Function to insert a new node at the end of the list
struct Node *insertatEnd(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return head;
}

// Function to insert a new node before a given node with the given data
struct Node *insertBeforeElement(struct Node *head, int data, int key)
{
    struct Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    if (head->data == key)
    {
        newNode->next = head;
        return newNode;
    }
    struct Node *ptr = head;
    while (ptr->next != NULL && ptr->next->data != key)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL)
    {
        printf("element not found in the list \n");
        free(newNode);
        return head;
    }
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

// Function to delete the first node of the list
struct Node *deleteFromBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return head;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node of the list
struct Node *deleteFromEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return head;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }
    struct Node *ptr = head;
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
    return head;
}

// Function to delete the node after a given node with the given key
struct Node *deleteafterNode(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("list is empty\n");
        return head;
    }
    struct Node *ptr = head;
    while (ptr->next != NULL && ptr->data != key)
    {
        ptr = ptr->next;
    }
    if (ptr->next == NULL || ptr->next->next == NULL)
    {
        printf("node not found in the list\n");
        return head;
    }
    struct Node *del = ptr->next;
    ptr->next = ptr->next->next;
    free(del);
    return head;
}

// Function to print the list
void printList(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("%d -> NULL\n", ptr->data);
}

// Function to search for an element in the list
int search(struct Node *head, int key)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == key)
        {
            return 1;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return 0;
}

int main()
{
    struct Node *head = NULL;
    int ch, data, key, result;
    while (1)
    {
        printf("\nMenu:\n1.Insert at beginning.\n2.Insert after a given node.\n3.Insert at End.\n4.Delete from Beginning\n5.Delete from end\n6.Delete After Node\n7.Display List\n8.Search Element\n9.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter element to be inserted : ");
            scanf("%d", &data);
            head = insertatBeginning(head, data);
            break;
        case 2:
            printf("\n Enter element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the key before which to insert:");
            scanf("%d", &key);
            head = insertBeforeElement(head, data, key);
            break;
        case 3:
            printf("\n Enter element to be inserted : ");
            scanf("%d", &data);
            head = insertatEnd(head, data);
            break;
        case 4:
            head = deleteFromBeginning(head);
            break;
        case 5:
            head = deleteFromEnd(head);
            break;
        case 6:
            printf("\n Enter the key after which to be delete:");
            scanf("%d", &key);
            head = deleteafterNode(head, key);
            break;
        case 7:
            printList(head);
            break;
        case 8:
            printf("Enter Element to Search\n");
            scanf("%d", &key);
            result = search(head, key);
            if (result == 1)
            {
                printf("Element Found in the list\n");
            }
            else
            {
                printf("Element not found in the list\n");
            }
            break;
        case 9:
            printf("Exiting...");
            exit(1);
            break;
        default:
            printf("\n Wrong choice..Please enter again!");
            break;
        }
    }
    return 0;
}
//
// This code provides a menu-driven interface for the user to interact with the singly linked list. The user can perform operations like insertion, deletion, and search. The code also includes a function to print the list and a function to search for an element in the list.