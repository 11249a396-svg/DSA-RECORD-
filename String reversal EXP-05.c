***5.String reversal using stack:***

**Aim:**
To reverse a string using stack data structure by pushing each character into the stack and then popping them to get the reversed string.

**Algorithm:**
1.Start the program.
2.Read the size of the character stack MAX.
3.Allocate memory for the stack.
4.Read the input string of size MAX.
5.Push operation:
   For each character in the string, push it onto the stack.
6.Pop operation:
   Pop each character from the stack and print it to form the reversed string.
7.Free the allocated memory and end the program.

**Program:**
#include <stdio.h>
#include <stdlib.h>
int TOP = -1, MAX;
char* STACK;
void push(char item) {
    if (TOP == MAX - 1) {
        printf("STACK IS overflow\n");
    } else {
        TOP = TOP + 1;
        STACK[TOP] = item;
    }
}
char pop() {
    char item;
    if (TOP == -1) {
        printf("Stack is underflow/empty\n");
        return '\0';
    } else {
        item = STACK[TOP];
        TOP = TOP - 1;
        return item;
    }
}
void StringReversal() {
    char string[MAX + 1];
    printf("Please enter the string of size %d to reverse: ", MAX);
    scanf("%s", string);
    for (int c = 0; string[c] != '\0'; c++) {
        push(string[c]);
    }
    printf("Reversed string: ");
    while (TOP != -1) {
        printf("%c", pop());
    }
    printf("\n");
}
int main() {
    printf("Enter the size of CHAR STACK: ");
    scanf("%d", &MAX);
    STACK = (char*)realloc(STACK, MAX * sizeof(char)); 
    StringReversal();
    free(STACK);
    return 0;
}

**Output :**
Enter the size of CHAR STACK: 5
Please enter the string of size 5 to reverse: hello
Reversed string: olleh

Enter the size of CHAR STACK: 4
Please enter the string of size 4 to reverse: test
Reversed string: tset

**Result:**
The program To reverse a string using stack data structure by pushing each character into the stack and then popping them to get the reversed string was successfully implemented, executed, and the output was Verified.
