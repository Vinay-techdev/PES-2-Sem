#include <stdio.h>
#include <limits.h>

#define MAX 100

int minminEdge(int minEdge[], int visited[], int V) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && minEdge[v] < min) {
            min = minEdge[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printMST(int mst[], int graph[MAX][MAX], int V) {
    int totalCost = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");
    printf("Edge \tWeight\n");

    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", mst[i], i, graph[i][mst[i]]);
        totalCost += graph[i][mst[i]];
    }

    printf("\nTotal cost of MST = %d\n", totalCost);
}

void primMST(int graph[MAX][MAX], int V) {
    int mst[MAX];           // Stores MST
    int minEdge[MAX];      // Minimum weight edge value
    int visited[MAX];     // Track vertices included in MST

    for (int i = 0; i < V; i++) {
        minEdge[i] = INT_MAX;
        visited[i] = 0;
    }

    minEdge[0] = 0;      // Start from vertex 0
    mst[0] = -1;        // Root node

    for (int count = 0; count < V - 1; count++) {
        int u = minminEdge(minEdge, visited, V);

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < minEdge[v]) {
                mst[v] = u;
                minEdge[v] = graph[u][v];
            }
        }
    }

    printMST(mst, graph, V);
}

int main() {
    int V;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V);

    return 0;
}