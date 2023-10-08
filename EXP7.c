#include <stdio.h>
#include <stdlib.h>

int count = 0;

struct node {
    int data;
    struct node *next;
} *head, *t, *prev, *newNode, *t1;

void initialisehead() {
    head = NULL;
}

void insertBeginning(int val) {
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        t = head;
        while (t->next != head) {
            t = t->next;
        }
        t->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    count++;
}

void insertEnd(int val) {
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    t = head;
    if (t == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        while (t->next != head) {
            t = t->next;
        }
        t->next = newNode;
        newNode->next = head;
    }
    count++;
}

void insertCustom(int val) {
    if (head == NULL) {
        printf("\nNo such value found!");
    } else {
        newNode = (struct node *)malloc(sizeof(struct node));
        t = head;
        while (t->next != head) {
            if (t->data == val) {
                printf("\nEnter value of the new node: ");
                scanf("%d", &newNode->data);
                newNode->next = t->next;
                t->next = newNode;
                count++;
                return;
            }
            t = t->next;
        }
        if (t->data == val) {
            printf("\nEnter value of the new node: ");
            scanf("%d", &newNode->data);
            newNode->next = head;
            t->next = newNode;
            count++;
        }
    }
}

void deleteEnd() {
    if (head == NULL) {
        printf("\nEmpty Linked List!");
    } else {
        t = t1 = head;
        if (t->next == head) {
            head = NULL;
            free(t);
        } else {
            t = t->next;
            while (t->next != head) {
                t1 = t;
                t = t->next;
            }
            t1->next = head;
            free(t);
        }
        count--;
    }
}

void deleteStart() {
    if (head == NULL) {
        printf("\nEmpty Linked List!");
    } else {
        t = head;
        prev = head;
        if (t->next != head) {
            t = t->next;
            t1 = head;
            while (t1->next != head) {
                t1 = t1->next;
            }
            t1->next = t;
            head = t;
            free(prev);
        } else {
            head = NULL;
            free(t);
        }
        count--;
    }
}

void deleteCustom(int val) {
    if (head == NULL) {
        printf("\nEmpty Linked List!");
    } else {
        t = head;
        if (t->next == head && t->data == val) {
            head = NULL;
            free(t);
            count--;
        } else {
            t = t->next;
            prev = head;
            while (t->next != head) {
                if (t->data == val) {
                    prev->next = t->next;
                    free(t);
                    count--;
                    return;
                }
                prev = t;
                t = t->next;
            }
            if (t->data == val) {
                prev->next = NULL;
                free(t);
                count--;
            }
        }
    }
}

void display() {
    printf("\nList: ");
    t = head;
    while (t->next != head) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("%d ", t->data);
}

int main() {
    int choice, val;

    while (1) {
        printf("\nMenu:");
        printf("\n1. Initialise Head");
        printf("\n2. Insert at the beginning");
        printf("\n3. Insert at the end");
        printf("\n4. Insert after a specific value");
        printf("\n5. Delete from the beginning");
        printf("\n6. Delete from the end");
        printf("\n7. Delete a specific value");
        printf("\n8. Display the list");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initialisehead();
                printf("Head initialised.\n");
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d", &val);
                insertBeginning(val);
                break;
            case 3:
                printf("Enter the value to insert: ");
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
