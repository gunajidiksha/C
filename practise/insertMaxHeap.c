#include <stdio.h>

void insertHeap(int a[25], int *n, int value) {
    (*n)++;
    a[*n] = value;
    int i = *n;

    while (i > 1) {
        int parent = i / 2;
        if (a[parent] > a[i]) {
            // Swap the elements
            int temp = a[parent];
            a[parent] = a[i];
            a[i] = temp;

            i = parent;
        } else {
            return;  // No value should be returned in a void function
        }
    }
}

void printHeap(int a[25], int n) {
    printf("Min Heap: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[26];  // Assuming index 0 is not used
    int heapSize = 0;
    int value , n;

    printf("Enter number of elements : ");
    scanf("%d" , &n);
    // Example: Inserting elements into the min heap from user input
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        insertHeap(a, &heapSize, value);
    }

    // Print the min heap
    printHeap(a, heapSize);

    return 0;
}
