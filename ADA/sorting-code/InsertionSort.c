#include <stdio.h>

// int main() {

//     int arr[] = {13, 46, 999, 9, 34, 76, 3, 0};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     for (int i = 1; i <= n - 1; i++) {

//         int j = i-1;
//         int v = arr[i];

//         while (j >= 0 && arr[j] > v) {

//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = v;
//     }

//     // Print sorted array
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }

//     return 0;
// }

int main(){

    int arr[] = {13, 46, 999, 9, 34, 76, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 1; i <= n-1; i++)
    {
        int value = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > value){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = value;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    

    return 0;
}