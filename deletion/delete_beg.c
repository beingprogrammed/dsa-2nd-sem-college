#include <stdio.h>
void main()
{
    int a[10], i, n, item;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter array element a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    printf("\nThe array entered : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    item = a[0];

    printf("\nAfter deleting the first element : ");

    for (i = 0; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    for (i = 0; i < n - 1; i++)
    {
        printf("%d\t", a[i]);
    }
}