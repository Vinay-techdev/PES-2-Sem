#include <stdio.h>
#include <math.h>

#define THRESHOLD 16   // small size → insertion sort

/* Swap */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* INSERTION SORT (as per slide) */
void insertion_sort(int arr[], int low, int high) {
    for (int i = low + 1; i <= high; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* HEAPIFY */
void heapify(int arr[], int n, int i, int offset) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[offset + left] > arr[offset + largest])
        largest = left;

    if (right < n && arr[offset + right] > arr[offset + largest])
        largest = right;

    if (largest != i) {
        swap(&arr[offset + i], &arr[offset + largest]);
        heapify(arr, n, largest, offset);
    }
}

/* HEAP SORT (as per slide idea) */
void heap_sort(int arr[], int low, int high) {
    int n = high - low + 1;

    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i, low);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[low], &arr[low + i]);
        heapify(arr, i, 0, low);
    }
}

/* PARTITION (Hoare style from slide) */
int partition_func(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i >= j)
            break;

        swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
    return j;
}

/* INTROSORT (exact slide logic) */
void introsort(int arr[], int low, int high, int depth_limit) {
    int size = high - low + 1;

    if (low >= high)
        return;

    if (size < THRESHOLD) {
        insertion_sort(arr, low, high);
        return;
    }

    if (depth_limit == 0) {
        heap_sort(arr, low, high);
        return;
    }

    int p = partition_func(arr, low, high);

    introsort(arr, low, p - 1, depth_limit - 1);
    introsort(arr, p + 1, high, depth_limit - 1);
}
 
/* Print */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* MAIN */
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 3, 2, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    int depth_limit = 2 * floor(log2(n));
    introsort(arr, 0, n - 1, depth_limit);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}