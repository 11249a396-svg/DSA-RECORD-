***4.Queue operations using Array:***

**Aim:**
To implement a queue using an array and perform enqueue (insertion) and dequeue (deletion) operations.

**Algorithm:**

*Enqueue Operation:*
1.Check if the queue is full (rear == SIZE-1). If yes, display "Queue Overflow".
2.If the queue is empty (front == -1), set front = 0.
3.Increment rear by 1.
4.Insert the item at queue[rear].
5.Display "Item inserted successfully".

*Dequeue Operation:*
1.Check if the queue is empty (front == -1). If yes, display "Queue Underflow".
2.Store queue[front] in a variable item.
3.If front == rear, set front = rear = -1 (queue becomes empty).
4.Else, increment front by 1.
5.Display "Deleted item: item".

**Program:**
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int item) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = item;
        printf("%d inserted into the queue.\n", item);
    }
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
    } else {
        printf("%d deleted from the queue.\n", queue[front]);
        front++;
    }
}

// Display queue elements
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

// Main function
int main() {
    int choice, item;
    do {
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert (Enqueue)\n");
        printf("2. Delete (Dequeue)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
**Output:**
Item inserted Successfully: 10
Item inserted Successfully: 20
Item inserted Successfully: 30
Item inserted Successfully: 40
Deleted item: 10
Deleted item: 20


**Result:**
The program successfully inserts 4 elements into the queue and deletes 2 elements from the front, maintaining the FIFO (First In First Out) principle of a queue.
