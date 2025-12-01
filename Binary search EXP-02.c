**Aim:**
To write a program to search an element in an array using Binary Search.

**Algorithm:**
1.Start
2.Input the size of the array n.
3.Input the array elements A, A, ... A[n-1] in sorted order.
4.Input the element to search, say key.
5.Set low=0, high=n-1.
6.Repeat until low <= high:
  Compute mid = (low+high)/2
  If A[mid] == key, then print "Element found at position mid+1" and Stop.
  Else if A[mid] < key, Set low=mid+1.
  Else Set high = mid-1
7.If low > high, print "Element not found".
8.Stop.

**program:**
#include <stdio.h>

int main() {
    int n, key, low, high, mid, i, found = 0;

    // Input size of array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int A[n];

    // Input sorted array elements
    printf("Enter %d elements in sorted order:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Input the element to search
    printf("Enter the element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    // Binary Search
    while (low <= high) {
        mid = (low + high) / 2;

        if (A[mid] == key) {
            printf("Element found at position: %d\n", mid + 1);
            found = 1;
            break;
        } else if (A[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        printf("Element not found\n");
    }

    return 0;
}

**output:**
INPUT:
Enter the Size of Array: 5
Enter 5 Elements in Sorted Array: 4, 6, 8, 9, 12
Enter the element to Search: 10
OUTPUT:
Element found at position: 4

**Result:**
The program to Search an element in an array using Binary Search was successfully implemented, executed, and the output was Verified.
