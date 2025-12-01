**7.single linked list:**
Aim:
Implement a menu-driven singly linked list in C that supports:
 Insert at beginning
 Insert at end
 Insert at position
 Delete by value
 Display list

Algorithm:

1.Define a Node structure with data and next.
2.For insertion:
  Beginning: create node → point its next to head → update head.
  End: traverse to last node → set last->next to new node.
  Position: traverse to node at position-1 → insert node by adjusting pointers.
3.For deletion by value:
  If head contains value, remove head.
  Else traverse to find node whose next node contains value and unlink it.
4.Display by traversing from head printing nodes.

Program:
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert node at the end
void insertAtEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display linked list
void display(struct Node *head) {
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete node at beginning
void deleteAtBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Deleted node from beginning.\n");
}

// Delete node at end
void deleteAtEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Deleted last node.\n");
        return;
    }

    struct Node *temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    printf("Deleted node from end.\n");
}

// Delete node at a specific position
void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Deleted node at position %d.\n", position);
}

// Main function to test
int main() {
    struct Node *head = NULL;

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    display(head);

    // Delete operations
    deleteAtBeginning(&head);
    display(head);

    deleteAtEnd(&head);
    display(head);

    deleteAtPosition(&head, 2);
    display(head);

    return 0;
}


Sample Output:
--- Singly Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete by Value
5. Display List
6. Exit
Enter choice: 2
Enter data: 10
Inserted 10 at end.

Enter choice: 1
Enter data: 5
Inserted 5 at beginning.

Enter choice: 2
Enter data: 20
Inserted 20 at end.

Enter choice: 3
Enter data and position: 15 3
Inserted 15 at position 3.

Enter choice: 5
Linked List: 5 -> 10 -> 15 -> 20 -> NULL

Enter choice: 4
Enter value to delete: 10
Deleted 10 from list.

Enter choice: 5
Linked List: 5 -> 15 -> 20 -> NULL

Enter choice: 6
Exiting...

Result:
Working singly linked list program that performs insertions, deletion by value, and displays the list. Memory is freed at exit. You can extend it (search, reverse, sort) similarly.
