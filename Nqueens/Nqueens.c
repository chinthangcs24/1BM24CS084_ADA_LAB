#include <stdio.h>
#include <stdlib.h>

int place(int x[], int k) {
    for (int i = 1; i < k; i++) {
        if (x[i] == x[k] || abs(x[i] - x[k]) == k - i)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    printf("Enter n: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *x = calloc(n + 1, sizeof(int));
    int k = 1;
    x[k] = 0;

    while (k > 0) {
        x[k]++;
        while (x[k] <= n && !place(x, k))
            x[k]++;
        if (x[k] <= n) {
            if (k == n) {
                for (int i = 1; i <= n; i++)
                    printf("%d ", x[i]);
                printf("\n");
            } else {
                k++;
                x[k] = 0;
            }
        } else {
            k--;
        }
    }

    free(x);
    return 0;
}
