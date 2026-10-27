#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;

node *head, *end;

int n; // Number of nodes specified by user

void createlist(); // To create a linked list of n nodes
void printlist();  // To print the list

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createlist(); // Call to create a linked list of n nodes
    printlist();  // Print the list

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

        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &temp->info);

        temp->link = NULL;

        if (head == NULL)
            head = temp;
        else
            end->link = temp;

        end = temp;
    }
}

void printlist()
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}