#include <stdio.h>
void main()
{
    int a[10], i, n, item;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the array element a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    printf("\nThe array you entered is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    item = a[n - 1];
    a[n - 1] = NULL;

    printf("\nAfter deleting the last element : ");

    for (i = 0; i < n - 1; i++)
    {
        printf("%d\t", a[i]);
    }
}