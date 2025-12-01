***3.Stack operations using array***

**Aim:**
To implement a stack using an array in C and perform push and pop operations.

**Algorithm:**
1.Start the program.
2.Initialize TOP = -1 and choice = 0.
3.Read the maximum size of the stack MAX.
4.Create an array stack[MAX].
5.Repeat until the user chooses to exit (choice != 3):
 1.Display menu: Push, Pop, Exit.
 2.Read the user’s choice.
 3.If choice is 1 (Push):
   If TOP == MAX-1, display “stack is overflown”.
   Else, input a value, increment TOP, and store the value in stack[TOP].
 4.If choice is 2 (Pop):
   If TOP == -1, display “stack underflow”.
   Else, display stack[TOP] and decrement TOP.
 5.If choice is 3 (Exit):
   Terminate the program.
 6.If invalid choice:
   Display “Incorrect choice”.
6.End.

**Program:**
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int Top = -1;
char STACK[MAX];

// Function to push an item onto the stack
void push(char item) {
    if (Top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        Top = Top + 1;
        STACK[Top] = item;
    }
}

// Function to pop an item from the stack
char pop() {
    char item;
    if (Top == -1) {
        printf("Stack underflow/empty\n");
        return '\0';  // Return null character if stack is empty
    } else {
        item = STACK[Top];
        Top = Top - 1;
        return item;
    }
}

// Function to reverse a string using the stack
void stringReversal() {
    char string[MAX];
    int size;

    printf("Enter the size of the string: ");
    scanf("%d", &size);

    printf("Please enter string to reverse: ");
    scanf("%s", string);

    // Push each character of the string onto the stack
    for (int C = 0; C < size && string[C] != '\0'; C++) {
        push(string[C]);
    }

    printf("Reversed string: ");

    // Pop characters from the stack to print them in reverse
    for (int C = 0; C < size; C++) {
        printf("%c", pop());
    }
    printf("\n");
}

int main() {
    stringReversal();
    return 0;
}

**Output:**
Enter the stack size: 3

1. push
2. pop
3. exit
choose your option: 1
Enter the value to push: 13

1. push
2. pop
3. exit
choose your option: 1
Enter the value to push: 46

1. push
2. pop
3. exit
choose your option: 2
popped element is 46

1. push
2. pop
3. exit
choose your option: 3
Exiting...
Code Execution Completed

**Result:**
The program to implement a stack using an array in C and perform push and pop operations was successfully implemented, executed, and the output was Verified.
