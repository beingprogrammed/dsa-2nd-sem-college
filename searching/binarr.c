#include <stdio.h>

int binarySearch(int arr[], int n, int key)
{
    int beg = 0, end = n - 1, mid;
    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    int n, key, index;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array in sorted order:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    index = binarySearch(arr, n, key);
    if (index != -1)
        printf("%d found at index %d\n", key, index);
    else
        printf("%d not found in the array\n", key);
    return 0;
}