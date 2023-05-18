#include <stdio.h>
#include <conio.h>
#include <math.h>

int a[30], count = 0;

// Function to check if a queen can be placed at a given position
int place(int pos) {
    int i;
    for(i = 1; i < pos; i++) {
        if ((a[i] == a[pos]) || (abs(a[i] - a[pos]) == abs(i - pos)))
            return 0;  // Not a valid position
    }
    return 1;  // Valid position to place a queen
}

// Function to print the current solution
void print_sol(int n) {
    int i, j;
    count++;
    printf("\n\nSolution #%d:\n", count);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(a[i] == j)
                printf("Q\t");  // Print 'Q' for queen position
            else
                printf("*\t");  // Print '*' for empty position
        }
        printf("\n");
    }
}

// Function to solve the N-queens problem
void queen(int n) {
    int k = 1;
    a[k] = 0;
    while(k != 0) {
        a[k] = a[k] + 1;
        while((a[k] <= n) && !place(k))
            a[k]++;
        if(a[k] <= n) {
            if(k == n)
                print_sol(n);  // Solution found
            else {
                k++;
                a[k] = 0;  // Move to the next row
            }
        }
        else
            k--;  // Backtrack to the previous row
    }
}

int main() {
    int n;
    printf("Enter the number of Queens\n");
    scanf("%d", &n);
    queen(n);  // Solve N-queens problem
    printf("\nTotal solutions = %d", count);
    getch();  // Wait for a key press before exiting
    return 0;
}
