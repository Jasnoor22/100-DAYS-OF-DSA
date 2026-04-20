#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

struct Pair
{
    struct Node* node;
    int hd;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n, int i)
{
    if(i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);

    return root;
}

int main()
{
    int n, i;
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    if(root == NULL)
        return 0;

    int values[200][200], count[200] = {0};
    int offset = 100;

    struct Pair queue[200];
    int front = 0, rear = 0;

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    int minHD = 0, maxHD = 0;

    while(front < rear)
    {
        struct Pair temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        values[hd + offset][count[hd + offset]++] = curr->data;

        if(hd < minHD) minHD = hd;
        if(hd > maxHD) maxHD = hd;

        if(curr->left)
        {
            queue[rear].node = curr->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        if(curr->right)
        {
            queue[rear].node = curr->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    for(i = minHD; i <= maxHD; i++)
    {
        int j;
        for(j = 0; j < count[i + offset]; j++)
            printf("%d ", values[i + offset][j]);
        printf("\n");
    }

    return 0;
}