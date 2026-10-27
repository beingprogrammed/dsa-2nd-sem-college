#include <stdio.h>
#define MAX_SIZE 10 // Maximum size of the stack

int stack[MAX_SIZE]; // Array to store elements in the stack
int top = -1;        // Index of the top element in the stack

void push(int element)
{
    if (top >= MAX_SIZE - 1)
    { // Check if the stack is full
        printf("Error: Stack overflow\n");
        return;
    }
    top++;
    stack[top] = element;
}

int pop()
{
    if (top < 0)
    { // Check if the stack is empty
        printf("Error: Stack underflow\n");
        return -1;
    }
    int element = stack[top];
    top--;
    return element;
}

void printStack()
{
    if (top < 0)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int numElements;
    printf("Enter the number of elements in the stack (up to 10): ");
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

    int poppedElement = pop();
    printf("Popped element: %d\n", poppedElement);
    printf("Updated stack after popping: - \n");
    printStack();
    return 0;
}