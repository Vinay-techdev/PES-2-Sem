#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Edge structure
typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];
int parent[MAX];

// Find (with path compression)
int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

// Union
void unionSet(int a, int b) {
    parent[a] = b;
}

// Sort edges by weight
int compare(const void *a, const void *b) {
    Edge *e1 = (Edge *)a;
    Edge *e2 = (Edge *)b;
    return e1->w - e2->w;
}

void kruskal(int V, int E) {
    int i, count = 0, cost = 0;

    // Sort edges
    qsort(edges, E, sizeof(Edge), compare);

    // Initialize parent
    for (i = 0; i < V; i++)
        parent[i] = i;

    printf("\nEdges in MST:\n");

    for (i = 0; i < E; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        // If no cycle
        if (u != v) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            unionSet(u, v);
            count++;

            if (count == V - 1)
                break;
        }
    }

    printf("\nTotal cost of MST = %d\n", cost);
}

int main() {
    int V, E;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v w):\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(V, E);

    return 0;
}