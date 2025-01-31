// Stack Using Linked List

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node
{
    int data;
    struct Node* next;
    int size;
} Node;

// initialize the Node

Node* create(int data )
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->data = data;
    new_node->size = 0;

    return new_node;
}

// stack of nodes

typedef struct Stack
{
    Node* head;
    int size;
} Stack;

// initializer

Stack* initialize()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    stack->size = 0;

    return stack;
}

int isEmpty(Stack* stack)
{
    return stack->head == NULL;
}

void push(Stack* stack, int data)
{
    // create a node
    Node* new_node = create(data);

    new_node->next = stack->head;
    stack->head = new_node;
    stack->size += 1;
}

int pop(Stack* stack)
{
    // check if the node is empty or not
    if(isEmpty(stack))
    {
        printf("Stack Underflow\n");
        return -1;
    }

    stack->size -= 1;
    Node* temp = stack->head;
    
    int data = stack->head->data;
    stack->head = stack->head->next;

    free(temp);

    return data;
}

int peek(Stack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack Underflow");
        return -1;
    }

    int data = stack->head->data;
    return data;
}

int size(Stack* stack)
{
    return stack->size;
}


int main()
{
    Stack *stack = initialize();

    int operation;

    printf("Stack using Linked List\n");
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
}
