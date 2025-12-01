AIM:

To implement a Binary Search Tree (BST) and perform Preorder, Inorder, and Postorder traversals in C.

ALGORITHM:

1.Start the program.
2.Create a structure Node with data, left pointer, and right pointer.
3.Create a function createNode() to generate a new node.
4.Insert elements into the BST using the insert() function.
5.Perform Preorder traversal using preorder() function.
6.Perform Inorder traversal using inorder() function.
7.Perform Postorder traversal using postorder() function.
7.Display all traversal outputs.
8.Stop the program.

PROGRAM:

#include <stdio.h>
#include <stdlib.h>

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

// Preorder - Root -> Left -> Right
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder - Left -> Root -> Right
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder - Left -> Right -> Root
void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{

    int n, value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert dynamically into BST
    }

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}

OUTPUT

INPUT:
Enter number of elements: 5
Enter 5 values:
50 30 70 20 40

OUTPUT:
Preorder Traversal: 50 30 20 40 70
Inorder Traversal: 20 30 40 50 70
Postorder Traversal: 20 40 30 70 50

RESULT:

The Binary Search Tree was successfully created.

Preorder, Inorder, and Postorder traversals were executed and displayed correctly.
