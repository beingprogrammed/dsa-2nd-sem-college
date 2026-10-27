#include <stdio.h>
void main()
{
    int a[10], i, n, item, loc;
    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter element a[%d] : ", i);
        scanf("%d", &a[i]);
    }

    printf("\nThe array entered : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\nEnter the new element for inserting : ");
    scanf("%d", &item);

    printf("\nEnter location for insertion : ");
    scanf("%d", &loc);

    if (loc > n + 1 || loc <= 0)
    {
        printf("\nThe location doesn't exist");
    }

    else
    {
        for (i = n - 1; i >= loc - 1; i--)
        {
            a[i + 1] = a[i];
        }

        a[loc - 1] = item;

        printf("\nThe array after insertion : ");

        for (i = 0; i <= n; i++)
        {
            printf("%d\t", a[i]);
        }
    }
}