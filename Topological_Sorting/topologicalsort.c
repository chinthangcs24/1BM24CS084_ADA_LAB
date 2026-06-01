#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of vertices: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of vertices.\n");
        return 1;
    }
    int **adj = malloc(n * sizeof(int *));
    if (!adj) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        adj[i] = calloc(n, sizeof(int));
        if (!adj[i]) {
            fprintf(stderr, "Memory allocation failed.\n");
            return 1;
        }
    }
    printf("Enter adjacency matrix (0 or 1) row by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &adj[i][j]) != 1) {
                fprintf(stderr, "Invalid adjacency matrix input.\n");
                return 1;
            }
        }
    }
    int *indegree = calloc(n, sizeof(int));
    int *check = calloc(n, sizeof(int));
    int *topo = malloc(n * sizeof(int));
    if (!indegree || !check || !topo) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] != 0) {
                indegree[j]++;
            }
        }
    }
    int count = 0;
    while (1) {
        int w = -1;
        for (int i = 0; i < n; i++) {
            if (check[i] == 0 && indegree[i] == 0) {
                w = i;
                break;
            }
        }
        if (w == -1) {
            break;
        }
        topo[count++] = w + 1; 
        check[w] = 1;

        for (int v = 0; v < n; v++) {
            if (adj[w][v] != 0) {
                indegree[v]--;
            }
        }
    }
    if (count < n) {
        printf("No Topological Sequence\n");
    } else {
        printf("Topological Sequence: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(indegree);
    free(check);
    free(topo);
    return 0;
}
