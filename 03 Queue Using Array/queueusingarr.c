

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50

typedef struct 
{
    int *arr;
    int rear;
    int front;
}Queue;

// initialize the Queue
Queue* initialize()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (int*)malloc(MAX_SIZE * sizeof(int));
    queue->front = -1;
    queue->rear = -1;

    return queue;
}

// is empty
int isEmpty(Queue* queue)
{
    return (queue->front == -1 && queue->rear ==-1);
}

int isFull(Queue* queue)
{
    return (queue->rear == MAX_SIZE);
}

// enqueue
void enqueue(Queue *queue, int data)
{
    // check if queue is full or not 
    if(isFull(queue))
    {
        printf("Queue overflow\n");
        return;
    }
    if(queue->front == -1)
    {
        queue->front = 0;
    }
    queue->arr[++queue->rear] = data;
}

int dqueue(Queue* queue)
{
    // check if queue is empty or not
    if(isEmpty(queue))
    {
        printf("Queue underflow\n");
        return -1;
    }
    int item = queue->arr[queue->front];
    queue->front++;

    if(queue->front > queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }

    return item;
}


int peek(Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue underflow\n");
        return -1;
    }
    return queue->arr[queue->front];
}

// size;

int size(Queue* queue)
{
    if(isEmpty(queue)) return 0;
    return((queue->rear - queue->front) + 1);
}


int main()
{
    Queue *queue = initialize(50);
    int operation;

    printf("Queue using Array\n");
    printf("Enter the option given below to perform operation on a empty stack\n");
    printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. size\n");

    while(scanf("%d", &operation) == 1)
    {
        if(operation == 1)
        {
            int data;
            printf("Enter the number to be pushed into the stack: ");
            scanf("%d", &data);
            enqueue(queue, data);
        }
        else if(operation == 2)
        {
            int data = dqueue(queue);
            if(data != -1)
            {
                printf("%d is poped from the stack\n", data);
            }
        }
        else if(operation == 3)
        {
            if(peek(queue) != -1)
            printf("%d is the peek elemnet of stack\n", peek(queue));
        }
        else if(operation == 4)
        {
            if(isEmpty(queue))
            {
                printf("Stack is empty\n");
            }
            else 
            {
                printf("Stack is not empty\n");
            }
        }
        else if(operation == 5)
        {
            printf("Size of stack == %d\n", size(queue));
        }
        else
        {
            break;
        }
    }
    return 0;
}
