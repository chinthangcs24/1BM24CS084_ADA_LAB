#include <stdio.h>
#include <stdlib.h>

#define INF 99999

void printSolution(int **dist, int n) {
    printf("Shortest distances between every pair of vertices:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

void floydWarshall(int **dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    int **dist = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dist[i] = malloc(n * sizeof(int));
    }

    printf("Enter adjacency matrix values (use %d for no edge):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    floydWarshall(dist, n);
    printSolution(dist, n);

    for (int i = 0; i < n; i++) {
        free(dist[i]);
    }
    free(dist);
    return 0;
}
