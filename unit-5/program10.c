/*
A transportation network contains cities connected by roads with different costs. Write a C 
program implementing Dijkstra’s Shortest Path Algorithm that accepts the number of vertices,
weighted adjacency matrix and source vertex, computes the minimum distance from the source to 
every other vertex, and displays each destination with its shortest distance. Test it using at least 
five vertices. */
#include <stdio.h>

# define INF 1000000
    int n, source;
    int adj[100][100];
    int dist[100];
    int visited[100] = {0};

    void dijkstra(int src);

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the weighted adjacency matrix:\n");
    printf("Use 0 for no edge and positive integers for edge weights\n");
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    do
    {
        scanf("%d", &source);
        if (source < 1 || source > n) 
        {
            printf("Please enter a value between 1 and %d : ", n);
        }
    }
    while (source < 1 || source > n);
    source--; // Adjusted for 0-based indexing
    dijkstra(source);
}

void dijkstra(int src) 
{
    for (int i = 0; i < n; i++) 
    {
        dist[i] = INF; // Initialize all distances to a large value
    }
    dist[src] = 0; // Distance from source to itself is 0

    for (int i = 0; i < n; i++) 
    {
        int u = -1;
        for (int j = 0; j < n; j++) 
        {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) 
            {
                u = j;
            }
        }
        if (u == -1|| dist[u] == INF) 
        {
            break;
        }
        visited[u] = 1;
        for (int v = 0; v < n; v++) 
        {
            if (adj[u][v] > 0 && !visited[v]) 
            {
                if (dist[u] + adj[u][v] < dist[v]) 
                {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", src + 1);
    for (int i = 0; i < n; i++) 
    {
        printf("To vertex %d: %d\n", i + 1, dist[i]);
    }
}