

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* create(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
}

typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

Queue* initialize()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

int isEmpty(Queue *queue)
{
    return (queue->front == NULL);
}

void enqueue(Queue *queue, int data)
{
    Node* new_node = create(data);

    if(queue->rear == NULL)
    {
        queue->front = queue->rear = new_node;
    }
    else 
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

int dqueue(Queue *queue)
{
    if(queue->front == NULL)
    {
        printf("Queue Underflow\n");
        return -1;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;

    if(queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    return data;

}

int peek(Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

int size(Queue* queue)
{
    int count = 0;
    Node* temp = queue->front;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;    
}

int main()
{
    Queue *queue = initialize();
    int operation;

    printf("Queue Using Linked List\n");
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