#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *link;
} node;

node *head, *end;

int n; // Number of nodes specified by user

void createlist();  // To create a linked list of n nodes
void deletebegin(); // To delete a node from beginning
void printlist();   // To print the list

int main()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    createlist(); // Call to create a linked list of n nodes
    printlist();  // Print the list before deletion

    deletebegin(); // Delete a node from beginning
    printlist();   // Print the list after deletion

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

void deletebegin()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    node *temp;
    temp = head;
    head = head->link;
    free(temp);

    printf("\nAfter deletion first node : ");
}

void printlist()
{
    node *temp;
    temp = head;
    printf("\nThe linked list is : ");
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->link;
    }
    printf("\n");
}