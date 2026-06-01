#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

typedef struct {
    int value;
    int direction;
} Element;

void printPermutation(Element *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i].value);
    }
    printf("\n");
}

int isMobile(Element *arr, int i, int n) {
    if (arr[i].direction == LEFT && i > 0) {
        return arr[i].value > arr[i - 1].value;
    }
    if (arr[i].direction == RIGHT && i < n - 1) {
        return arr[i].value > arr[i + 1].value;
    }
    return 0;
}

int findLargestMobileIndex(Element *arr, int n) {
    int largestMobileIndex = -1;
    for (int i = 0; i < n; i++) {
        if (isMobile(arr, i, n)) {
            if (largestMobileIndex == -1 || arr[i].value > arr[largestMobileIndex].value) {
                largestMobileIndex = i;
            }
        }
    }
    return largestMobileIndex;
}

void reverseDirectionsOfGreater(Element *arr, int n, int mobileValue) {
    for (int i = 0; i < n; i++) {
        if (arr[i].value > mobileValue) {
            arr[i].direction = (arr[i].direction == LEFT) ? RIGHT : LEFT;
        }
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    Element *arr = malloc(n * sizeof(Element));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i].value = i + 1;
        arr[i].direction = LEFT;
    }

    printf("Johnson-Trotter permutations:\n");
    printPermutation(arr, n);

    while (1) {
        int mobileIndex = findLargestMobileIndex(arr, n);
        if (mobileIndex == -1) {
            break;
        }

        int swapIndex = (arr[mobileIndex].direction == LEFT) ? mobileIndex - 1 : mobileIndex + 1;

        Element temp = arr[mobileIndex];
        arr[mobileIndex] = arr[swapIndex];
        arr[swapIndex] = temp;

        reverseDirectionsOfGreater(arr, n, arr[swapIndex].value);

        printPermutation(arr, n);
    }

    free(arr);
    return 0;
}
