#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
    int data;
    struct StackNode *next;
};

struct StackNode *top = NULL;

void push(int element)
{
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (newNode == NULL)
    {
        printf("Error: Memory allocation failed\n");
        return;
    }
    newNode->data = element;
    newNode->next = top;
    top = newNode;
}

void printStack()
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    struct StackNode *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int numElements, newElement;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &numElements);
    printf("Enter the elements in the stack:\n");
    for (int i = 0; i < numElements; i++)
    {
        int element;
        scanf("%d", &element);
        push(element);
    }
    printf("Current stack: - \n");
    printStack();
    printf("Enter thenew element to be pushed onto the stack: ");
    scanf("%d", &newElement);
    push(newElement);
    printf("Updated stack: - \n");
    printStack();
    return 0;
}