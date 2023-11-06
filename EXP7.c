#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to initialize the head for a circular linked list
void initialiseHead() {
    head = (struct Node *)malloc(sizeof(struct Node));
    head->next = head; // Points to itself initially
}

// Function to insert a node at the beginning of the circular linked list
void insertBeginning(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;

    if (head == NULL) {
        head = newNode;
        head->next = head; // Points to itself initially
    } else {
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
        head = newNode;
    }
}

// Function to insert a node at the end of the circular linked list
void insertEnd(int val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;

    if (head == NULL) {
        head = newNode;
        head->next = head; // Points to itself initially
    } else {
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to insert a node after a specific value in the circular linked list
void insertCustom(int val) {
    if (head == NULL) {
        printf("Empty Circular Linked List!\n");
    } else {
        int newVal;
        printf("Enter the value of the new node: ");
        scanf("%d", &newVal);

        struct Node *current = head;
        do {
            if (current->data == val) {
                struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                newNode->data = newVal;
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        } while (current != head);

        printf("No such value found!\n");
    }
}

// Function to delete a node from the beginning of the circular linked list
void deleteStart() {
    if (head == NULL) {
        printf("Empty Circular Linked List!\n");
    } else {
        struct Node *temp = head;
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        head = head->next;
        current->next = head;
        free(temp);
    }
}

// Function to delete a node from the end of the circular linked list
void deleteEnd() {
    if (head == NULL) {
        printf("Empty Circular Linked List!\n");
    } else {
        struct Node *current = head;
        struct Node *prev = NULL;
        while (current->next != head) {
            prev = current;
            current = current->next;
        }
        if (current == head) {
            head = NULL;
        } else {
            prev->next = head;
        }
        free(current);
    }
}

// Function to delete a node with a specific value from the circular linked list
void deleteCustom(int val) {
    if (head == NULL) {
        printf("Empty Circular Linked List!\n");
    } else {
        struct Node *current = head;
        struct Node *prev = NULL;
        do {
            if (current->data == val) {
                if (prev == NULL) {
                    head = head->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
                return;
            }
            prev = current;
            current = current->next;
        } while (current != head);
        printf("Value not found!\n");
    }
}

// Function to display the circular linked list
void display() {
    if (head == NULL) {
        printf("Empty Circular Linked List!\n");
        return;
    }

    struct Node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("->head\n");
}


int main() {
    int choice, val;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Initialise Head\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Insert after a specific value\n");
        printf("5. Delete from the beginning\n");
        printf("6. Delete from the end\n");
        printf("7. Delete a specific value\n");
        printf("8. Display the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initialiseHead();
                printf("Head initialised.\n");
                break;
            case 2:
                printf("Enter the value to insert at the beginning: ");
                scanf("%d", &val);
                insertBeginning(val);
                break;
            case 3:
                printf("Enter the value to insert at the end: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 4:
                printf("Enter the value after which to insert: ");
                scanf("%d", &val);
                insertCustom(val);
                break;
            case 5:
                deleteStart();
                break;
            case 6:
                deleteEnd();
                break;
            case 7:
                printf("Enter the value to delete: ");
                scanf("%d", &val);
                deleteCustom(val);
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
