#include <stdio.h>

#define MAX_EDGES 20
#define MAX_VERTICES 10

typedef struct {
    int u, v, w;
} Edge;

void sortEdges(Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int findSet(int parent[], int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unionSet(int parent[], int x, int y) {
    parent[y] = x;
}

int main() {
    int V, E;
    Edge edges[MAX_EDGES];
    int parent[MAX_VERTICES];

    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &V);
    printf("Enter number of edges (max %d): ", MAX_EDGES);
    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        printf("Enter edge %d (u v w): ", i + 1);
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    sortEdges(edges, E);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    printf("Edges in MST:\n");
    int count = 0, totalWeight = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int setU = findSet(parent, u);
        int setV = findSet(parent, v);
        if (setU != setV) {
            printf("%d - %d : %d\n", u, v, edges[i].w);
            totalWeight += edges[i].w;
            unionSet(parent, setU, setV);
            count++;
        }
    }

    printf("Total weight = %d\n", totalWeight);
    return 0;
}
