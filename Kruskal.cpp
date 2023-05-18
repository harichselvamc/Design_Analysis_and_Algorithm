#include <iostream>
#include <climits>

int find(int i, int parent[]);
int uni(int i, int j, int parent[]);

int main()
{
    int i, j, k, a, b, u, v, n, ne = 1;
    int min, mincost = 0, cost[9][9], parent[9] = {};

    std::cout << "\nEnter the no. of vertices: ";
    std::cin >> n;

    std::cout << "\nEnter the cost adjacency matrix:\n";
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            std::cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }

    std::cout << "\nThe edges of Minimum Cost Spanning Tree are:\n\n";
    while (ne < n)
    {
        for (i = 1, min = INT_MAX; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u, parent);
        v = find(v, parent);

        if (uni(u, v, parent))
        {
            std::cout << ne << " edge (" << a << "," << b << ") =" << min << "\n";
            mincost += min;
        }

        cost[a][b] = cost[b][a] = INT_MAX;
    }

    std::cout << "\nMinimum cost = " << mincost << "\n";

    return 0;
}

int find(int i, int parent[])
{
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j, int parent[])
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
