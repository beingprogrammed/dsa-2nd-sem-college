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
void insertloc();  // To insert a node at specified location
void printlist();  // To print the list

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createlist(); // Call to create a linked list of n nodes
    printlist();  // Print the list before insertion

    printf("Enter the location to insert: ");
    scanf("%d", &loc);
    insertloc(); // Insert a node at specified location
    printlist(); // Print the list after insertion

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

void insertloc()
{
    if (loc > n + 1 || loc <= 0)
    {
        printf("Location doesn't exist. List remains same.\n");
        return;
    }

    int item;
    node *temp, *newnode;

    printf("Enter the info for the new node: ");
    scanf("%d", &item);

    newnode = (node *)malloc(sizeof(node));
    newnode->info = item;

    if (loc == 1)
    {
        // Insert at beginning
        newnode->link = head;
        head = newnode;
    }
    else if (loc == 2)
    {
        temp = head;
        newnode->link = temp->link;
        temp->link = newnode;
    }
    else
    {
        temp = head;
        for (int i = 0; i < loc - 2; i++)
            temp = temp->link;

        newnode->link = temp->link;
        temp->link = newnode;
    }

    printf("\nAfter insertion at %d location : ", loc);
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