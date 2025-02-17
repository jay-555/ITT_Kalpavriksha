// Stack using 2 queue 


#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Queue 
{
    int *arr;
    int rear;
    int front;
} Queue;

Queue* init()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (int*)malloc(MAX * sizeof(int));
    q->rear = -1;
    q->front = -1;
    
    return q;
}

int isempty(Queue* q)
{
    return (q->front == -1);
}

int isfull(Queue* q)
{
    return (q->rear == MAX - 1);
}


void enqueue(Queue* q, int data)
{
    if(isfull(q))
    {
        return;
    }
    
    if(q->front == -1) q->front = 0;
    
    q->rear = (q->rear + 1) % MAX;
    
    q->arr[q->rear] = data;
}

int dqueue(Queue *q)
{
    if(isempty(q))
    {
        return -1;
    }
    
    int data = q->arr[q->front];
    
    if(q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front+ 1) % MAX; 
    }
    
    return data;
}


typedef struct stack 
{
    Queue *q1;
    Queue *q2;
} Stack;


Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->q1 = init();
    s->q2 = init();
    
    return s;
}


void push(Stack* s, int data)
{
    enqueue(s->q1, data);
}

int pop(Stack* s)
{
    if(isempty(s->q1))
    {
        return -1;
    }
    
    for(int i = s->q1->front; i < s->q1->rear; i++)
    {
        enqueue(s->q2, dqueue(s->q1));
    }
    
    int data = dqueue(s->q1);
    
    Queue* temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
    
    return data;
}

int size(Stack* s)
{
    if(isempty(s->q1))
    {
        return 0;
    }
    
    int len = ((s->q1->rear) - (s->q1->front) + 1);
    
    return len;
    
}

int main()
{
    // printf("Hello World");
    Stack *s = initStack();
    
    push(s, 10);
    push(s, 20);
    push(s, 30);

    
    printf("%d ", pop(s));
    printf("%d ", pop(s));
    
    //     push(s, 40);
    // push(s, 10);
    // printf("%d ", pop(s));
    // printf("%d ", pop(s));
    
    printf("%d", size(s));

    return 0;
}