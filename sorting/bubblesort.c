#include <stdio.h>

void bubbleSort(int arr[], int n);
void swap(int *a, int *b);

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Array before sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    bubbleSort(arr, n);

    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}