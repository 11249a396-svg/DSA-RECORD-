**10.Circular queue operations using linked list:**
AIM:
To implement Circular Queue operations (Enqueue, Dequeue, Display) using Linked List in C.

ALGORITHM:
1. ENQUEUE (Insert)
1. Create a new node.
2. If queue is empty:
front = rear = new node
rear->next = front
3. Else:
rear->next = new node
rear = new node
rear->next = front
2. DEQUEUE (Delete)
1. If queue is empty → print “Queue is empty”.
2. If front == rear:
Remove single node
front = rear = NULL
3. Else:
temp = front
front = front->next
rear->next = front
free temp
3. DISPLAY
1. If empty → print “Queue empty”.
2. Start from front.
3. Traverse until node again becomes front.
C PROGRAM — Circular Queue Using Linked List
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *next;
};

// Pointers for front and rear
struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front; // Circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }
    printf("%d inserted\n", x);
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) { 
        // Only one node in the queue
        printf("%d deleted\n", front->data);
        front = rear = NULL;
    } else {
        printf("%d deleted\n", front->data);
        front = front->next;
        rear->next = front; // Maintain circular link
    }
    free(temp);
}

// Display circular queue
void display() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;
    printf("Circular Queue: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

// Main function
int main() {
    int choice, x;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid Choice\n");
        }
    }
}


  SAMPLE OUTPUT:
1.Enqueue
2.Dequeue
3.Display
4.Exit
Enter choice: 1
Enter value: 10
10 inserted
Enter choice: 1
Enter value: 20
20 inserted
Enter choice: 1
Enter value: 30
30 inserted
Enter choice: 3
Circular Queue: 10 20 30
Enter choice: 2
10 deleted
Enter choice: 3
Circular Queue: 20 30
