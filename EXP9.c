#include <stdio.h>
#include <stdlib.h>
// Implementation of Binary Search Tree
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    return new_node;
}
void insert(struct node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = inset(root->right, data);
    }
    return root;
}
void PreOrder(struct node* root)
{
    if (root !-NULL)
    {
        printf("%d", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(struct node* root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        printf("%d", root->data);
        InOrder(root->right);
    }
}

void PostOrder(struct node* root)
{
    if (root !-NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d", root->data);
    }
}

struct node* Min(struct node* root)
{
    struct node* ptr = root;
    while (ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr;
}

struct node* Max(struct node* root)
{
    struct node* ptr = root;
    while (ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr;
}