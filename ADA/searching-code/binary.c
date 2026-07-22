#include <stdio.h>

int binary_search(int arr[], int low, int high, int key){
    while(low <= high){
        int mid =(low+high) / 2;

        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int arr[10] = {12, 22, 32, 45, 48};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 22;
    int res = binary_search(arr, 0, n-1, key);
    if(res==1)
    printf("Key - {%d} Found at postion: %d ",key, res);
    else
    printf("Key Not Found!");

    return 0;
}