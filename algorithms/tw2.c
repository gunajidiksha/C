#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000

int A[MAX], B[MAX];
void MergeSort(int low, int high);
void Merge(int low, int mid, int high);

int main() {
    int n, i, j;
    int low, high, mid;
    clock_t s, e;
    double cpu_exec_t;

    printf("Please Enter the size of the array: ");
    scanf("%d", &n);
    low = 0;
    high = n - 1;

    for (i = 0; i < n; i++) {
        A[i] = rand() % 100;
    }

    printf("The array elements are: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    s = clock();
    for (i = 0; i < 10000; i++) {
        MergeSort(low, high);
    }
    e = clock();
    cpu_exec_t = (double)(e - s) / CLK_TCK;

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("CPU Execution time is %lf\n", cpu_exec_t);
    return 0;
}

void MergeSort(int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        MergeSort(low, mid);
        MergeSort(mid + 1, high);
        Merge(low, mid, high);
    }
}

void Merge(int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j]; 
            j++;
        }
        k++;
    }

    while (i <= mid) {
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high) {
        B[k] = A[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++) {
        A[i] = B[i];
    }
}
