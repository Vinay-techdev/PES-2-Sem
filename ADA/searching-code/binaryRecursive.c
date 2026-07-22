#include <stdio.h>

int binary_search(int arr[], int low, int high, int key){
    
    if(low>high) return -1;

    int mid = (low+high) / 2;

    if(arr[mid] == key) return mid;

    else if(arr[mid] < key) binary_search(arr, mid+1, high, key);
    else binary_search(arr, low, mid-1, key);
}

int main(){
    int arr[] = {12, 22, 34, 56, 59, 67};
    int n = sizeof(arr) / sizeof(arr[0]);

    int res = binary_search(arr, 0, n-1, 22);
    if(res==-1)
    printf("Key Not Found!");
    else
    printf("Key Found at postion: %d ", res);

    return 0;
}