AIM:

To construct a Binary Search Tree (BST) and perform Level Order Traversal (Breadth-First Search) using a queue in C.

ALGORITHM:

1.Start the program.
2.Create a structure Node with data, left pointer, and right pointer.
3.Create a function createNode() to generate a new tree node.
4.Insert elements into the BST using the insert() function.
5.Implement queue operations using an array of Node pointers (enqueue() and dequeue()).
6.Perform level order traversal using levelOrder() by processing nodes in FIFO order.
7.Display the Level Order Traversal output.
8.Stop the program.

PROGRAM:

#include <stdio.h>
#include <stdlib.h>

struct Node **queue;
int front = -1, rear = -1, MAX;

// Structure for tree node
// Data, Pointer to left child and Pointer to right child
struct Node
{
    int data;
    struct Node *left, *right;
};

// Node creation
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert the new node and returns root node of the updated tree
struct Node *insert(struct Node *root, int value)
{
    // First node will be root node
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Queue implementation for Level Order Traversal / BFS


void enqueue(struct Node *temp)
{
    if (rear == MAX-1)
        return; // Queue full
    if (front == -1)
        front = 0;
    queue[++rear] = temp;
}

struct Node *dequeue()
{
    if (front == -1 || front > rear)
        return NULL; // Empty
    return queue[front++];
}

void levelOrder(struct Node *root)
{
    if (root == NULL)
        return;

    enqueue(root);

    while (front <= rear)
    {
        struct Node *current = dequeue();
        printf("%d ", current->data);

        if (current->left != NULL)
            enqueue(current->left);
        if (current->right != NULL)
            enqueue(current->right);
    }
}

int main()
{
    int value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &MAX);

    queue = (struct Node **)malloc(MAX * sizeof(struct Node *));

    printf("Enter %d values:\n", MAX);

    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert dynamically into BST
    }

    printf("\nLevel Order Traversal: ");
    levelOrder(root);

    return 0;
}

OUTPUT: 
SAMPLE INPUT
Enter number of elements: 7
Enter 7 values:
50 30 70 20 40 60 80

OUTPUT
Level Order Traversal: 50 30 70 20 40 60 80

RESULT

The Binary Search Tree was successfully constructed.

Level Order Traversal was performed using a queue and the nodes were displayed in BFS order.
