#include <stdio.h>

int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {

        // Check if target is within range
        if (arr[low] > target || arr[high] < target)
            return -1;

        // If only one element
        if (arr[low] == target)
            return low;

        // Interpolation formula
        int pos = low + ((target - arr[low]) * (high - low)) /
                           (arr[high] - arr[low]);

        // Target found
        if (arr[pos] == target)
            return pos;

        // Search left side
        else if (arr[pos] > target)
            high = pos - 1;

        // Search right side
        else
            low = pos + 1;
    }

    return -1; // Not found
}

int main() {
    int arr[] = {2, 6, 8, 8, 14, 14, 18, 22, 24, 35, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 22;

    int result = interpolationSearch(arr, n, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}