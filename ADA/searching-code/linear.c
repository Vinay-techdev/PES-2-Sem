#include <stdio.h>

int linear_search(int arr[], int n, int key)
{

    arr[n] = key;
    int i = 0;

    while (arr[i] != key)
    {
        i++;
    }

    if (i < n)
        return i;
    else
        return -1;
}

int main()
{
    int arr[] = {12, 22, 32, 45, 48};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key = 46;

    int res = linear_search(arr, n, key);
    if (res == -1)
        printf("Key Not Found!");
    else
        printf("Key Found at postion: %d ", res);

    return 0;
}