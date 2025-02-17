// Queue using 2 std::stack<T> ;




#include <stdio.h>
#include <stdlib.h>
#define MAX 50

typedef struct Stack
{
    int *arr;
    int top;
} Stack;

Stack* init()
{
    Stack* st = (Stack*)malloc(sizeof(Stack));
    st->arr = (int*)malloc(MAX *sizeof(int));
    st->top = -1;
    
    return st;
}

int isempty(Stack *s)
{
    return (s->top == -1);
}

int isfull(Stack* s)
{
    return (s->top == MAX - 1);
}

void push(Stack *s, int data)
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

int size(Stack* s)
{
    return (s->top + 1);
}


// Queue 

typedef struct Queue 
{
    Stack* s1;
    Stack* s2;
} Queue;


Queue *initQueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->s1 = init();
    q->s2 = init();
    
    return q;
}

void enqueue(Queue* q, int data)
{
    push(q->s1, data);
}

int dqueue(Queue *q)
{
    int data;
    if(!(isempty(q->s2)))
    {
        data = pop(q->s2);
    }
    else
    {
        while(!isempty(q->s1))
        {
            push(q->s2, pop(q->s1));
        }
        data = pop(q->s2);
    }
    return data;
}

int main()
{
    // printf("Hello World");
    Queue *q = initQueue();
    
    enqueue(q, 10);
    
    printf("%d ", dqueue(q));
    printf("%d ", dqueue(q));
    
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    
    printf("%d ", dqueue(q));
    printf("%d ", dqueue(q));
    printf("%d ", dqueue(q));
    printf("%d ", dqueue(q));

    return 0;
}