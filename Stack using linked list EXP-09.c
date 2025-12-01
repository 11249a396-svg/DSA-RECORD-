**8.Stack using linked list:**
AIM:
To implement stack operations (PUSH, POP, DISPLAY) using a linked list in C.

 ALGORITHM
1. Start
2. Create a structure Node
Each node contains:
int data
struct Node *next
3. Initialize
struct Node *top = NULL;
4. PUSH(x) Operation
1. Create a new node.
2. Store the value x in newnode->data.
3. Set newnode->next = top.
4. Update top = newnode.
5. Display "x pushed".
5. POP() Operation

1. If top == NULL, print "Stack is Empty".
2. Else
Store top in temporary pointer temp.
Print "temp->data popped".
Move top = top->next.
Free the node.
6. DISPLAY() Operation
1. If top == NULL, print "Stack is Empty".
2. Else
Start from top.
Traverse while t != NULL
Print each t->data.
Move to next node.
7. In main()

1. Use a loop to display menu:
1. PUSH
2. POP
3. DISPLAY
4. EXIT
2. Perform operation based on choice.
8. Stop

PROGRAM (as it is from your notes)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// push operation
void push(int x) {
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
    printf("%d pushed\n", x);
}

// pop operation
void pop() {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("%d popped\n", top->data);
        struct Node *temp = top;
        top = top->next;
        free(temp);
    }
}

// display operation
void display() {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    struct Node *t = top;
    printf("Stack: ");
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    do {
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
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

OUTPUT (same as your notebook):
1. PUSH
2. POP
3. DISPLAY
4. EXIT
Enter your choice: 1
Enter Value: 10
10 pushed
Enter your choice: 1
Enter Value: 20
20 pushed
Enter your choice: 3
Stack: 20 10
Enter your choice: 2
20 popped
Enter your choice: 3
Stack: 10
Enter your choice: 4
Exiting...

RESULT:
The stack operations PUSH, POP and DISPLAY were successfully implemented using a linked list in C and executed correctly.
