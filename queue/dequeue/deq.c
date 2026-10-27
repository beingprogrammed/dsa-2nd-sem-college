#include <stdio.h>
#define MAX_SIZE 10 // Maximum size of the queue

int queue[MAX_SIZE]; // Array to store elements in the queue
int front = -1;      // Index of the front element in the queue
int rear = -1;       // Index of the rear element in the queue

void enqueue(int element)
{
    if (rear == MAX_SIZE - 1)
    { // Check if the queue is full
        printf("Error: Queue overflow\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = element;
}

void printQueue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Error: Queue underflow\n");
        return -1;
    }
    int element = queue[front];
    front++;
    return element;
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
    printf("Current queue: - \n");
    printQueue();

    int dequeuedElement = dequeue();
    if (dequeuedElement != -1)
    {
        printf("Dequeued element: %d\n", dequeuedElement);
    }
    printf("Updated queue: - \n");
    printQueue();

    return 0;
}