#include <stdio.h>

int main(void) {
    float profits[3];
    int weights[3];
    float x[3] = {0.0f, 0.0f, 0.0f};
    int maxcap;
    float profit = 0.0f;

    printf("Enter profits\n");
    for (int i = 0; i < 3; i++) {
        scanf("%f", &profits[i]);
    }

    printf("Enter weights\n");
    for (int i = 0; i < 3; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter max capacity\n");
    scanf("%d", &maxcap);

    float ratio[3];
    for (int i = 0; i < 3; i++) {
        ratio[i] = profits[i] / weights[i];
    }

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (ratio[i] < ratio[j]) {
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                float tempProfit = profits[i];
                profits[i] = profits[j];
                profits[j] = tempProfit;

                int tempWeight = weights[i];
                weights[i] = weights[j];
                weights[j] = tempWeight;
            }
        }
    }

    int i = 0;
    while (i < 3 && maxcap > 0) {
        if (weights[i] <= maxcap) {
            x[i] = 1.0f;
            maxcap -= weights[i];
            profit += profits[i];
            i++;
        } else {
            break;
        }
    }

    if (i < 3 && maxcap > 0) {
        x[i] = (float)maxcap / weights[i];
        profit += x[i] * profits[i];
    }

    printf("Profit is %.2f\n", profit);
    printf("Items taken are\n");
    for (int k = 0; k < 3; k++) {
        printf("%.2f ", x[k]);
    }
    printf("\n");

    return 0;
}  
