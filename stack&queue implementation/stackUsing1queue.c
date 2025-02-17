// stack using 1 queue

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
} Stack;


Stack* initStack()
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->q1 = init();
    
    return s;
}


void push(Stack* s, int data)
{
    enqueue(s->q1, data);
}

int popRecursive(Queue *q) {
    // Base case: If only one element is left in the queue, dequeue and return it
    if (q->front == q->rear) {
        return dqueue(q);
    }

    // step 1: Dequeue the front element and store it temporarily veriable
    int temp = dqueue(q);

    // Step 2: Recursively call pop on the remaining queue 
    int result = popRecursive(q);

    // Step 3: Re-enqueue the temporarily stored element
    enqueue(q, temp);

    // Step 4: Return the result from the recursive call
    return result;
}

int pop(Stack *s) {
    if (isempty(s->q1)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return popRecursive(s->q1);
}



int main()
{
    Stack* s = initStack();
    
    push(s, 10);
    push(s, 20);
    // push(s, 30);

    
    printf("%d ", pop(s));
    printf("%d ", pop(s));
    
        push(s, 40);
    push(s, 10);
    printf("%d ", pop(s));
    // printf("%d ", pop(s));
}