// credits to Pratyusha Karanam

#include <stdio.h>
#include <stdlib.h>
int cost[100][100], cost1[100][100], adj[100], parent[100], key[100], key1[100], mincost = 0, n, x = 1, u, v;
int main()
{
    int i, j, k;
    printf("enter the number of vertices:");
    scanf("%d", &n);
    printf("enter the costs:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost1[i][j]);
            if (cost1[i][j] == 0)
                cost1[i][j] = 999;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cost[i][j] = cost1[i][j];
        }
    }
    for (i = 1; i < n; i++)
        key[i] = 999;
    key[0] = 0;
    key1[0] = 0;
    while (x < n)
    {
        u = extract_min();
        k = 0;
        for (i = 0; i < n; i++)
        {
            if (cost[u][i] != 999)
            {
                adj[k] = i;
                k++;
            }
        }
        for (i = 0; i < k; i++)
        {
            v = adj[i];
            if (cost[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = cost[u][v];
                key1[v] = cost[u][v];
                cost[u][v] = cost[v][u] = 999;
            }
        }
        key[u] = -1;
        x++;
    }
    printf("\nThe edges are:");
    for (i = 1; i < n; i++)
    {
        printf("\n%d--->%d : %d", parent[i] + 1, i + 1, cost1[parent[i]][i]);
    }
    for (i = 0; i < n; i++)
        mincost += key1[i];
    printf("\ncost=%d", mincost);
    return 0;
}
int extract_min()
{
    int i, min, pos = 0;
    min = 999;
    for (i = 0; i < n; i++)
    {
        if (key[i] < min && key[i] != -1)
        {
            min = key[i];
            pos = i;
        }
    }
    return pos;
}
