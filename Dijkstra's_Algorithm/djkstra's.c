#include <stdio.h>

#define MAX_VERTICES 10
#define INF 99999

int minDistance(int dist[], int visited[], int V) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

int main() {
    int V, src;
    int graph[MAX_VERTICES][MAX_VERTICES];
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};

    printf("Enter number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &V);
    if (V <= 0 || V > MAX_VERTICES) return 0;

    printf("Enter adjacency matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex (0 to %d): ", V - 1);
    scanf("%d", &src);
    if (src < 0 || src >= V) return 0;

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d: INF\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }

    return 0;
}