#include <stdio.h>
void main()
{
    int a[10], i, n, item;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the element a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    printf("\nThe array entered : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\nEnter the element to be inserted at the end : ");
    scanf("%d", &item);

    a[n] = item;

    printf("\nThe array after insertion : ");

    for (i = 0; i <= n; i++)
    {
        printf("%d\t", a[i]);
    }
}