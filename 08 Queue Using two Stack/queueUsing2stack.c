#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int *arr;
    int top;
    int capacity;
} Stack;

Stack* initializeStack(int capacity)
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

int isFull(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int data)
{
    if (isFull(stack))
    {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = data;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is Empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int size(Stack *stack)
{
    return stack->top + 1;
}

// Two Stacks using queue
typedef struct Queue
{
    Stack *stack1;
    Stack *stack2;
} Queue;

Queue* initializeQueue(int capacity)
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = initializeStack(capacity);
    queue->stack2 = initializeStack(capacity);
    return queue;
}

void enqueue(Queue *queue, int data)
{
    push(queue->stack1, data);
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue->stack2))
    {
        if (isEmpty(queue->stack1))
        {
            printf("Queue Underflow\n");
            return -1;
        }
        
        // element of stack1 to stack 2 
        while (!isEmpty(queue->stack1))
        {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    
    return pop(queue->stack2);
}

int peekQueue(Queue *queue)
{
    if (isEmpty(queue->stack2))
    {
        if (isEmpty(queue->stack1))
        {
            printf("Queue is Empty\n");
            return -1;
        }
    
        while (!isEmpty(queue->stack1))
        {
            push(queue->stack2, pop(queue->stack1));
        }
    }
    
    return peek(queue->stack2);
}

int sizeQueue(Queue *queue)
{
    return size(queue->stack1) + size(queue->stack2);
}

int main()
{
    Queue *queue = initializeQueue(50);

        printf("\nQueue using Two Stacks\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. isEmpty\n5. Size\n");
        printf("Enter operation: ");
        // scanf("%d", &operation);

    int operation;
    while (scanf("%d", &operation) == 1)
    {

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
            int data = peekQueue(queue);
            if (data != -1)
                printf("Front of the queue: %d\n", data);
        }
        else if (operation == 5)
        {
            printf("Size of the queue: %d\n", sizeQueue(queue));
        }
        else if (operation == 4)
        {
            if(isEmpty(queue->stack1))
                printf("Stak Underflow");
            else
                printf("Stack is not empty");
        }
        else
        {
            printf("Invalid option!\n");
            break;
        }
    }

    free(queue->stack1->arr);
    free(queue->stack2->arr);
    free(queue->stack1);
    free(queue->stack2);
    free(queue);

    return 0;
}
