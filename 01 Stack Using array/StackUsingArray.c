// STACK USING ARRAY


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack
{
    unsigned capacity;
    int top;
    int *arr;
}Stack;

Stack* initialize(unsigned capicity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(100*sizeof(int));
    stack->top = -1;
    stack->capacity = capicity;

    return stack;
}

int isEmpty(Stack* stack)
{
    return (stack->top == -1);
}

int isFull(Stack* stack)
{
    return (stack->top == stack->capacity -1);
}

int push(Stack* stack, int data)
{
    if(isFull(stack))
    {
        printf("Stack overflow\n");
        return -1;
    }

    stack->arr[++stack->top] = data;
    return 0;
}

int pop(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    int data = stack->arr[stack->top];
    stack->top--;
    return data;
}

int peek(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    return stack->arr[stack->top];
}

int size(Stack* stack)
{
    return (stack->top + 1);
}


int main()
{
    Stack *stack = initialize(100);
    
    int operation;

    printf("Stack using Array\n");
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
            printf("Size of stack == %d\n", size(stack));
        }
        else
        {
            break;
        }
    }
    return 0;
}