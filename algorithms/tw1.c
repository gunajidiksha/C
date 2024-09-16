#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key, result;
    clock_t s, e;
    double t;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int a[n];

    printf("Enter elements : ");
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        scanf("%d",&a[i]);
    }

    printf("Enter the element to be searched:\n");
    scanf("%d", &key);

    s = clock();
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 10000; j++) {
            result = binarySearch(a, n, key);
        }
    }
    e = clock();
    t = (double)(e - s) / CLOCKS_PER_SEC;

    if (result != -1)
        printf("Element is present at index %d\n", result);
    else
        printf("Element not found\n");

    printf("Time taken: %lf\n", t);
    return 0;
}