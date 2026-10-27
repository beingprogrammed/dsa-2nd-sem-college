#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

void printQueue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    struct Node *temp = queue->front;
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
    printf("Enter the number of elements in the queue: ");
    scanf("%d", &numElements);

    struct Queue *queue = createQueue();

    printf("Enter the elements in the queue:\n");
    for (int i = 0; i < numElements; i++)
    {
        int element;
        scanf("%d", &element);
        enqueue(queue, element);
    }

    printf("Current queue: - \n");
    printQueue(queue);

    printf("Enter the new element to be enqueued: ");
    scanf("%d", &newElement);
    enqueue(queue, newElement);

    printf("Updated queue: - \n");
    printQueue(queue);

    return 0;
}