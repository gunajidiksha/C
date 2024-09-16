#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int board[MAX][MAX];
int solution = 0;

int isItSafe(int i, int j, int N) {
    for (int r = 0; r < i; ++r)
        if (board[r][j]) return 0;

    int r = i, c = j;
    while (r >= 0 && c >= 0) {
        if (board[r][c]) return 0;
        r--; c--;
    }

    r = i, c = j;
    while (r >= 0 && c < N) {
        if (board[r][c]) return 0;
        r--; c++;
    }
    return 1;
}

void display(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void nQueens(int N, int r) {
    if (r == N) {
        solution++;
        printf("Solution %d:\n", solution);
        display(N);
        return;
    }
    for (int c = 0; c < N; c++) {
        if (isItSafe(r, c, N)) {
            board[r][c] = 1;
            nQueens(N, r + 1);
            board[r][c] = 0;
        }
    }
}

int main() {
    while (1) {
        int ch;
        printf("1. Enter the value of N:\n2. Exit the program\nEnter the choice: ");
        scanf("%d", &ch);
        if (ch == 1) {
            int N;
            printf("Enter the value of N: ");
            scanf("%d", &N);
            if (N > MAX) {
                printf("N is too large! Please enter a value less than or equal to %d.\n", MAX);
                continue;
            }
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; ++j)
                    board[i][j] = 0;

            solution = 0;
            nQueens(N, 0);
            if (solution == 0) {
                printf("No solution exists for N = %d.\n", N);
            } else {
                printf("Total number of solutions for N = %d: %d\n", N, solution);
            }
        } else if (ch == 2) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
