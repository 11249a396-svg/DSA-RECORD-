AIM:

To sort an array of elements using the Quick Sort algorithm in C.

ALGORITHM:

1.Read the number of elements and store them in an array.
2.Use the quickSort() function to recursively divide the array based on a pivot.
3.Partition the array using the partition() function.
4.Swap elements using swap() to place them in correct order.
5.Display the sorted array.
6.End the program.

PROGRAM:

#include <stdio.h>

//Swap the numbers / Call by referene to persist changes
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition 
int partition(int list[], int low, int high)
{
    int pivot = list[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }
    swap(&list[i + 1], &list[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int list[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(list, low, high);
        quickSort(list, low, pi - 1);
        quickSort(list, pi + 1, high);
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int list[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i]);

    quickSort(list, 0, n - 1);

    printf("Sorted array (Quick Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);

    return 0;
}

OUTPUT:

SAMPLE INPUT
Enter number of elements: 6
Enter 6 elements:
20 5 18 9 1 30

OUTPUT
Sorted array (Quick Sort): 1 5 9 18 20 30

RESULT

The given list was successfully sorted using Quick Sort.

The sorted output is displayed in ascending order.
