#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

struct Node* mirrorTree(struct Node* root) {
    if (root == NULL) {
        return root;
    }

    struct Node* temp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);

    return root;
}

int countInternalNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return 0;
    }
    return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

int countExternalNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countExternalNodes(root->left) + countExternalNodes(root->right);
}

struct Node* search(struct Node* root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }

    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int findHeight(struct Node* root) {
    if (root == NULL) {
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int findSmallest(struct Node* root) {
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

int findLargest(struct Node* root) {
    struct Node* current = root;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

int main() {
    struct Node* root = NULL;
    int choice, value;
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Inorder Traversal\n");
        printf("5. Delete a Node\n");
        printf("6. Create Mirror Image\n");
        printf("7. Count Internal Nodes\n");
        printf("8. Count External Nodes\n");
        printf("9. Search\n");
        printf("10. Height of the Tree\n");
        printf("11. Find Smallest Element\n");
        printf("12. Find Largest Element\n");
        printf("13. Exit\n");
        while(1)
        {
                   printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Preorder Traversal: ");
                preorderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("Postorder Traversal: ");
                postorderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 6:
                root = mirrorTree(root);
                printf("Mirror image created.\n");
                break;
            case 7:
                printf("Number of Internal Nodes: %d\n", countInternalNodes(root));
                break;
            case 8:
                printf("Number of External Nodes: %d\n", countExternalNodes(root));
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("Element found in the tree.\n");
                } else {
                    printf("Element not found in the tree.\n");
                }
                break;
            case 10:
                printf("Height of the Tree: %d\n", findHeight(root));
                break;
            case 11:
                printf("Smallest Element: %d\n", findSmallest(root));
                break;
            case 12:
                printf("Largest Element: %d\n", findLargest(root));
                break;
            case 13:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        }

    

    return 0;
}
