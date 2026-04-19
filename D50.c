#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data)
{
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else if(data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct Node* search(struct Node* root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main()
{
    struct Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int key = 60;
    struct Node* result = search(root, key);

    if(result != NULL)
        printf("Found");
    else
        printf("Not Found");

    return 0;
}