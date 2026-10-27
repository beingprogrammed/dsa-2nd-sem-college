#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;

node *head, *end;

int n, loc; // Number of nodes and location specified by user

void createlist(); // To create a linked list of n nodes
void deletenode(); // To delete a node at specified location
void printlist();  // To print the list

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createlist(); // Call to create a linked list of n nodes
    printlist();  // Print the list before deletion

    printf("Enter the location to delete: ");
    scanf("%d", &loc);
    deletenode(); // Delete a node at specified location
    printlist();  // Print the list after deletion

    return 0;
}

void createlist()
{
    int i;
    head = NULL;
    end = NULL;

    for (i = 0; i < n; i++)
    {
        node *temp;
        temp = (node *)malloc(sizeof(node));

        printf("Enter the info for node %d: ", i + 1);
        scanf("%d", &temp->info);

        temp->link = NULL;

        if (head == NULL)
            head = temp;
        else
            end->link = temp;

        end = temp;
    }
}

void deletenode()
{
    if (loc > n || loc <= 0)
    {
        printf("Location doesn't exist. List remains same.\n");
        return;
    }

    node *temp, *prev;
    temp = head;

    if (loc == 1)
    {
        // Delete the first node
        head = temp->link;
        free(temp);
    }
    else
    {
        for (int i = 0; i < loc - 1; i++)
        {
            prev = temp;
            temp = temp->link;
        }

        prev->link = temp->link;
        free(temp);
    }
    printf("\nAfter deletion the %d location : ", loc);
}

void printlist()
{
    node *temp;
    temp = head;
    printf("\nThe list is : ");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}