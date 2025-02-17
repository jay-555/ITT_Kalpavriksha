#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Stack
{
    int *arr;
    int top;
} Stack;

Stack* init()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (int*)malloc(MAX * sizeof(int));
    s->top = -1;

    return s;
}

int isempty(Stack *s)
{
    return (s->top == -1);
}

int isfull(Stack* s)
{
    return (s->top == MAX - 1);
}

void push(Stack* s, int data)
{
    if(isfull(s))
    {
        return;
    }

    s->arr[++s->top] = data;
}

int pop(Stack* s)
{
    if(isempty(s))
    {
        return -1;
    }

    return s->arr[s->top--];
}

typedef struct Queue
{
    Stack* q;
} Queue;

Queue *initQueue()
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->q = init();

    return q;
}


void enqueue(Queue *q, int data)
{
    push(q->q, data);
}

int dqueue_helper(Stack* s)
{
    if(isempty(s))
    {
        return -1;
    }

    int data = pop(s);

    if(isempty(s))
    {
        return data;
    }

    int res = dqueue_helper(s);

    push(s, data);

    return res;
}

int dqueue(Queue *q)
{
    return (dqueue_helper(q->q));
}


int main()
{
    Queue* q = initQueue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);

    printf("Dequeued: %d\n", dqueue(q));
    printf("Dequeued: %d\n", dqueue(q));
    printf("Dequeued: %d\n", dqueue(q));
    printf("Dequeued: %d\n", dqueue(q));  // Attempt to dequeue from an empty queue

    return 0;
}