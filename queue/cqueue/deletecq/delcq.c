#include <stdio.h>
#define MAX_SIZE 10 // Maximum size of the queue

int queue[MAX_SIZE]; // Array to store elements in the queue
int front = -1;      // Index of the front element in the queue
int rear = -1;       // Index of the rear element in the queue

void enqueue(int element)
{
    if ((rear + 1) % MAX_SIZE == front)
    {
        printf("Error: Queue overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX_SIZE;
    }
    queue[rear] = element;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Error: Queue underflow\n");
        return -1;
    }
    int element = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
    return element;
}

void printQueue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE)
    {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[i]);
}

int main()
{
    int numElements;
    printf("Enter the number of elements in the queue (up to 10): ");
    scanf("%d", &numElements);
    printf("Enter the elements in the queue:\n");
    for (int i = 0; i < numElements; i++)
    {
        int element;
        scanf("%d", &element);
        enqueue(element);
    }
    printf("Current queue: -\n");
    printQueue();
    int dequeuedElement = dequeue();
    if (dequeuedElement != -1)
    {
        printf("Dequeued element: %d\n", dequeuedElement);
    }
    printf("Updated queue: -\n");
    printQueue();

    return 0;
}