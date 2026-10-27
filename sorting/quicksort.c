#include <stdio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
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

    quickSort(arr, 0, n - 1); //n-1, that is the last index is passed as high, thats where the high got the value

    printf("\nArray after sorting: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}