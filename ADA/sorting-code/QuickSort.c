#include <stdio.h>

// // Partition function
int partition(int arr[], int low, int high) {

    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        if (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Final swap of pivot
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}


// Quick Sort function
void quickSort(int arr[], int low, int high) {

    if (low < high) {

        int pIndex = partition(arr, low, high);

        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}


int main() {

    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before Quick Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nAfter Quick Sort:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}