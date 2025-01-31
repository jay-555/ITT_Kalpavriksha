// QUEUE USING ONE STACK


#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int capacity;
} Stack;


Stack* initializestk(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int data) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}


typedef struct Queue 
{
    Stack *stack;
} Queue;

Queue* initialize(int capacity) 
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->stack = initializestk(capacity);
    return queue;
}

int isEmptyQueue(Queue *queue)
{
    return isEmpty(queue->stack);
}

void enqueue(Queue *queue, int data) 
{
    push(queue->stack, data);
}

int dequeue(Queue *queue) 
{
    if (isEmpty(queue->stack)) 
    {
        printf("Queue Underflow\n");
        return -1;
    }

    int frontElement = -1;
    int size = queue->stack->top + 1;

    for (int i = 0; i < size - 1; i++) 
    {
        int temp = pop(queue->stack);
        push(queue->stack, temp);
    }

    frontElement = pop(queue->stack);
    return frontElement;
}

int peekQueue(Queue *queue) 
{
    if (isEmpty(queue->stack)) 
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int data = dequeue(queue);  
    enqueue(queue, data);
    return data;
}

int sizeQueue(Queue *queue) 
{
    return queue->stack->top + 1;
}

int main() {
    Queue *queue = initialize(50);
    int operation;
        
    printf("\nQueue using One Stack\n");
    printf("1. Enqueue\n2. Dequeue\n3. peek\n4. isEmpty\n5. Szie\n");
    printf("Enter operation: ");

    while (scanf("%d", &operation) == 1) {

        if (operation == 1) 
        {
            int data;
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(queue, data);
        }
        else if (operation == 2) 
        {
            int data = dequeue(queue);
            if (data != -1)
                printf("Dequeued: %d\n", data);
        }
        else if (operation == 3) 
        {
            printf("Size of the queue: %d\n", sizeQueue(queue));
        }
        else if (operation == 4) 
        {
            if (isEmptyQueue(queue)) {
                printf("Queue is empty\n");
            } else {
                printf("Queue is not empty\n");
            }
        }
        else if(operation == 5)
        {
            printf("Size of Queue: %d\n", sizeQueue(queue));
        }
        else 
        {
            printf("Invalid option!\n");
        }
    }

    free(queue->stack->arr);
    free(queue->stack);
    free(queue);

    return 0;
}