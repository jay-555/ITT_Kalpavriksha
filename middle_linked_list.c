#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct node
{
    int data;
    struct node* next;
} node;


node* create(int data)
{
    node* temp =  (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}


void intert_at_end(node* head, int data)
{
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    node *new_node = create(data);

    temp->next = new_node;
}

int length(node* head)
{
    int count = 0;
    node* temp = head;

    while(temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}


void middle(node *head)
{
    int len = length(head);
    int mid = len/2;

    if(len%2 != 0)
    {
        node* temp = head;
        while (mid > 0)
        {
            temp = temp->next;
            mid--;
        }
        printf("%d", temp->data); 
    }
    else
    {
        node* temp = head;
        while (mid > 0)
        {
            temp = temp->next;
            mid--;
        }
        
        printf("%d ", temp->data);
        printf("%d ", temp->next->data);
        
    }  
}


void display(node* head)
{
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


int main()
{   
    node* head;

    int element;
    int index = 1;
    
    printf("Enter the element of linked List (non integer to stop input): \n");

    while(1)
    {
       printf("Enter the %d element: ", index);
       
       if(scanf("%d", &element) == 1)
       {
            if(index == 1)
            {
                head = create(element);
            }
            else
            {
                intert_at_end(head, element);
            }
       }
       else
       {
           break;
       }
       index++;
    }

    display(head);
    printf("\nMiddle: ");
    middle(head);

    return 0;
}