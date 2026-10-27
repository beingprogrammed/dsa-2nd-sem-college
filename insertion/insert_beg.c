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

    printf("\nThe array entered : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\nEnter new element for inserting at beginning : ");
    scanf("%d", &item);

    for (i = n - 1; i >= 0; i--)
    {
        a[i + 1] = a[i];
    }
    a[0] = item;

    printf("\nThe array after insertion : ");

    for (i = 0; i <= n; i++)
    {
        printf("%d\t", a[i]);
    }
}