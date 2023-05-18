#include <stdio.h>
#include <conio.h>

#define infinity 999

void dij(int n, int v, int cost[10][10], int dist[10])
{
    // Function implementation remains the same
}

int main()
{
    int n, v, i, j, cost[10][10], dist[10];

    //clrscr(); // This function is commented out as it may not be available in all compilers

    printf("\n Enter the number of nodes:"); // Prompting the user to enter the number of nodes
    scanf("%d", &n); // Reading the number of nodes entered by the user

    printf("\n Enter the cost matrix:\n"); // Prompting the user to enter the cost matrix

    for (i = 1; i <= n; i++) // Loop for iterating through each row
        for (j = 1; j <= n; j++) // Loop for iterating through each column
        {
            scanf("%d", &cost[i][j]); // Reading the cost value at position (i, j) from the user

            if (cost[i][j] == 0) // If the cost value is zero, replace it with infinity
                cost[i][j] = infinity;
        }

    printf("\n Enter the source matrix:"); // Prompting the user to enter the source node
    scanf("%d", &v); // Reading the source node entered by the user

    dij(n, v, cost, dist); // Calling the dij function to calculate the shortest path

    printf("\n Shortest path:\n"); // Printing the heading for the shortest path

    for (i = 1; i <= n; i++) // Loop for iterating through each node
        if (i != v) // Exclude the source node from printing the shortest path
            printf("%d->%d, cost=%d\n", v, i, dist[i]); // Printing the shortest path from the source node to each node and its cost

    getch(); // Waits for a key press before exiting the program

    return 0; // Indicating successful program execution
}
