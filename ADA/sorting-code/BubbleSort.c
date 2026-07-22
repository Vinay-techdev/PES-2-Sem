#include <stdio.h>

int main() {
    
    // int arr[] = {1,2,3,4,5,6};
    int arr[] = {13, 46, 999, 9, 34, 76, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i <= n-2; i++) {

        for (int j = 0; j <= n-2-i; j++) {

            if (arr[j + 1] < arr[j]) {

                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted Array\n");

    // Print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}