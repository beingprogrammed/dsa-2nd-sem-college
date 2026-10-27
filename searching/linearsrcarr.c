#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int n, key, index;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    index = linearSearch(arr, n, key);
    if (index != -1)
        printf("%d found at location %d\n", key, index + 1);
    else
        printf("%d not found in the array\n", key);
    return 0;
}