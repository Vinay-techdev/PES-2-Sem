#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {

    int temp[100]; // temporary array (make sure size >= array size)
    int left = low;
    int right = mid + 1;
    int k = 0;

    // Merge in sorted order
    while (left <= mid && right <= high) {

        if (arr[left] <= arr[right]) {
            temp[k++] = arr[left++];
        } else {
            temp[k++] = arr[right++];
        }
    }

    // Remaining elements (left side)
    while (left <= mid) {
        temp[k++] = arr[left++];
    }

    // Remaining elements (right side)
    while (right <= high) {
        temp[k++] = arr[right++];
    }

    // Copy back to original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i-low];
    }
}

void mergeSort(int arr[], int low, int high) {

    if (low >= high) return;

    int mid = (low + high) / 2;

    mergeSort(arr, low, mid);        // left half
    mergeSort(arr, mid + 1, high);  // right half

    merge(arr, low, mid, high);     // merge
}

int main() {

    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("\n\nAfter sorting array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}