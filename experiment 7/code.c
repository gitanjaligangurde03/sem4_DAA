#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int board[MAX_SIZE], solutions = 0;

void printBoard(int n) {
    int i, j;
    printf("Solution %d:\n", solutions++);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (board[i] == j) {
                printf("Q ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int isSafe(int row, int col) {
    int i;
    for (i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

void solve(int n, int row) {
    int col;
    if (row == n) {
        printBoard(n);
    } else {
        for (col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                board[row] = col;
                solve(n, row + 1);
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    solve(n, 0);
    return 0;
}

