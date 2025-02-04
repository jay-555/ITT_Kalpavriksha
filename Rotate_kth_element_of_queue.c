

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct 
{
    int *arr;
    int top;
} Stack;

// initiaze stack

Stack* initialize_stack()
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(sizeof(int));
    stack->top = -1;

    return stack;
}


int isstackempty(Stack* stack)
{
    return (stack->top == -1);
}

int isstackfull(Stack* stack)
{
    return (stack->top == MAX_SIZE - 1);
}

void push(Stack *stack, int data)
{
    if(isstackfull(stack))
    {
        printf("Stack is full\n");
        return ;
    }

    stack->arr[++stack->top] = data;
}

int pop(Stack* stack)
{
    if(isstackempty(stack))
    {
        printf("Stack underflow");
        return -1;
    }

    int data = (stack->arr[stack->top]);
    stack->top--;

    return data;
}

// queue
typedef struct 
{
    int *arr;
    int rear;
    int front;
} Queue;

// initialize the queue
Queue* initialize()
{
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (int*)malloc(MAX_SIZE * (sizeof(int)));
    queue->front = -1;
    queue->rear = -1;

    return queue;
}

// check if queue is empty or not;
int isEmpty(Queue* queue)
{
    return (queue->front == -1  && queue->rear == -1);
}


int isFull(Queue* queue)
{
    return (queue->rear == MAX_SIZE-1);
}


void enqueue(Queue* queue, int data)
{
    if(isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }

    if(queue->front == -1) queue->front = 0;

    queue->rear++;
    queue->arr[queue->rear] = data;
}


int dqueue(Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty0000\n");
        return -1;
    }

    int data = queue->arr[queue->front];
    queue->front++;

    if(queue->front > queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    return data;
}

int size(Queue *queue)
{
    return (queue->rear - queue->front + 1);
}



void printQueue(Queue* queue)
{
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    for(int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}


//function to rotate kth element of the stack
void reverseKth_element_of_queue(Queue *queue, int k)
{
    // initialize stack
    Stack *stack = initialize_stack();
    int num = k;

    while(k)
    {
        push(stack, dqueue(queue));
        k--;
    }

    while(!isstackempty(stack))
    {
        enqueue(queue, pop(stack));
    }

    k  = size(queue) - num;

    while(k)
    {
        enqueue(queue, dqueue(queue));
        k--;
    }
}

int main()
{
    Queue* queue = initialize();
    int number;

    printf("Program to Rotate kth element in Queue\n");
    printf("Enter element to enqueue in queue: ");

    while (scanf("%d", &number) == 1)
    {
        enqueue(queue, number);
    }

    getchar();
    // take input of k
    int len = size(queue);
    int k;
    printf("\n Enter k: ");
    scanf("%d", &k);
    k = k % len;

    reverseKth_element_of_queue(queue, k);
    
    printQueue(queue);

    return 0;
}


