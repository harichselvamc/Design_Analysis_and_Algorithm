#include<stdio.h>
#include<conio.h>

// Declaring variables
int a, b, u, v, n, i, j, ne = 1; // ne is the number of edges
int visited[10] = {0}; // Array to keep track of visited nodes
int min, mincost = 0; // mincost keeps track of the minimum cost of the spanning tree
int cost[10][10]; // Adjacency matrix to store the costs of edges

int main()
{
    //clrscr(); // Clear the screen (commented out as this is a deprecated function)

    // Prompting user for the number of nodes
    printf("\n Enter the number of nodes:");
    scanf("%d", &n);

    // Prompting user to enter the adjacency matrix
    printf("\n Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // Assigning a large value to represent infinity
        }
    }

    visited[1] = 1; // Marking the first node as visited

    printf("\n");

    // Finding the minimum cost spanning tree using Prim's algorithm
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        // Checking if the selected edge is connected to an unvisited node
        if (visited[u] == 0 || visited[v] == 0)
        {
            // Printing the selected edge and its cost
            printf("\n Edge %d: (%d %d) cost: %d", ne++, a, b, min);
            mincost += min;

            visited[b] = 1; // Marking the visited node

            // Marking the selected edge as visited by assigning a large value to it
            cost[a][b] = cost[b][a] = 999;
        }
    }

    // Printing the minimum cost of the spanning tree
    printf("\n Minimum cost = %d", mincost);

    getch(); // Waiting for a key press before exiting

    return 0;
}
