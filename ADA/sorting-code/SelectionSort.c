#include <stdio.h>

int main() {

    int arr[] = {13, 46, 9, 34, 76};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i <= n - 2; i++) {

        int min = i;

        for (int j = i + 1; j <= n - 1; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swap
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}