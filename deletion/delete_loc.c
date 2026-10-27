#include <stdio.h>
void main()
{
    int a[10], n, i, item, loc;
    printf("Enter the number of elements in array : ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter the element a[%d] = ", i);
        scanf("%d", &a[i]);
    }
    printf("\nThe array you entered is : ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\nEnter the location of element you want to delete : ");
    scanf("%d", &loc);

    if (loc <= 0 || loc > n)
    {
        printf("\nThe location doesn't exist!");
    }
    else
    {
        item = a[loc - 1];
        for (i = loc - 1; i < n; i++)
        {
            a[i] = a[i + 1];
        }
        printf("\nThe array after deleting element %d : ", loc);

        for (i = 0; i < n - 1; i++)
        {
            printf("%d\t", a[i]);
        }
    }
}