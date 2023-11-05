#include <stdio.h>
#include <stdbool.h>
// Implementation of Breadth First Search and Depth First Search
it#define MAX_SIZE 100

int graph[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int n; // Number of vertices

void initializeGraph()
{
    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix (%d x %d):\n", n, n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &graph[i][j]);
        }
        visited[i] = false;
    }
}

void bfs(int start)
{
    int queue[MAX_SIZE];
    int front = -1, rear = -1;

    queue[++rear] = start;
    visited[start] = true;

    printf("BFS Traversal: ");

    while (front != rear)
    {
        int current = queue[++front];
        printf("%d ", current);

        for (int i = 0; i < n; ++i)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = true;
            }
        }
    }
    printf("\n");
}

void dfs(int vertex)
{
    printf("%d ", vertex);
    visited[vertex] = true;

    for (int i = 0; i < n; ++i)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    initializeGraph();

    int startVertex;
    printf("Enter the starting vertex for BFS and DFS: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= n)
    {
        printf("Invalid starting vertex.\n");
        return 1;
    }

    printf("Performing BFS traversal:\n");
    bfs(startVertex);

    // Reset visited array for DFS
    for (int i = 0; i < n; ++i)
    {
        visited[i] = false;
    }

    printf("Performing DFS traversal:\n");
    dfs(startVertex);
    printf("\n");

    return 0;
}