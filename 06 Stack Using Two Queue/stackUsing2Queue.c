



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50


typedef struct Queue
{
	int *arr;
	int rear;
	int front;
} Queue;


Queue* initialize()
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->arr = (int*)malloc(MAX_SIZE * sizeof(int));
	queue->rear = -1;
	queue->front = -1;
	
	return queue;
}

int isEmpty(Queue *queue)
{
	return (queue->rear == -1);
}

int isFull(Queue *queue)
{
	return (queue->rear == MAX_SIZE);
}


void enqueue(Queue *queue, int data)
{
	if(isFull(queue))
	{
		printf("Stack Underflow");
		return;
	}
	
	queue->arr[++queue->rear] = data;
	
	if(queue->front < 0)
	{
		queue->front = 0;
	}
}

int dequeue(Queue *queue)
{
	if(isEmpty(queue))
	{
		printf("Stack Underflow");
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


int peek(Queue *queue)
{
	if(isEmpty(queue))
	{
		printf("Stack Underflow");
		return -1;
	}
	
	return queue->arr[queue->rear];  //updated queue->front to queue->rear;
}

int size(Queue *queue)
{
	if(isEmpty(queue))
	{
		printf("Stack is Empty");
		return -1;
	}

	return (queue->rear - queue->front + 1);
}

int get_front(Queue *queue)
{
    return queue->front;
}

int get_rear(Queue *queue)
{
    return queue->rear;
}

void push(Queue* queue, int data)
{
    enqueue(queue, data);
}

int pop(Queue* queue)
{
    // Second Queue applied making pop operation costilear
    Queue *temp = initialize();

    while (!isEmpty(queue))  
    {
        enqueue(temp, dequeue(queue));
    }

    int data = dequeue(temp);

    while (!isEmpty(temp))
    {
        enqueue(queue, dequeue(temp));
    }

    return data;
}

int main()
{


    Queue *stack = initialize();
    int operation;

    printf("Stack using two Queue\n");
    printf("Enter the option given below to perform operation on a empty stack\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. size\n");

    while(scanf("%d", &operation) == 1)
    {
        if(operation == 1)
        {
            int data;
            printf("Enter the number to be pushed into the stack: ");
            scanf("%d", &data);
            push(stack, data);
        }
        else if(operation == 2)
        {
            int data = pop(stack);
            if(data != -1)
            {
                printf("%d is poped from the stack\n", data);
            }
        }
        else if(operation == 3)
        {
            if(peek(stack) != -1)
            printf("%d is the peek elemnet of stack\n", peek(stack));
        }
        else if(operation == 4)
        {
            if(isEmpty(stack))
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
			if(size(stack) != -1)
            	printf("Size of stack == %d\n", size(stack));
        }
        else
        {
            break;
        }
    }
    return 0;

}
