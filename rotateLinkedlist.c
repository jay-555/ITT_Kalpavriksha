// 1 2 3 4 => 2 3 4 1

#include <stdio.h>
#include <stdlib.h>


typedef struct  node
{
    int data;
    struct node* next;    
} node;


node* create(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

void insert_at_end(node** head, int data)
{
    node* new_node = create(data);

    if(*head == NULL)
    {
        *head = new_node;
    }
    else{
        node* temp = *head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}





void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

node* rotate(node* head, int k)
{
    node* temp = head;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    k = (k % count);

    if(k == 0)
    {
        return head;
    }

    temp = head;

    for(int i = 1; i < (count - k) && temp != NULL ; i++)
    {
        temp = temp->next;
    }

    node* new_head = temp->next;
    temp->next = NULL;

    node* last = new_head;

    while(last->next != NULL)
    {
        last = last->next;
    }

    last->next = head;
    
    return new_head;
}

int main()
{
    node* head = NULL;
    int data;
    int k;

    printf("Enter the data of Linked List: ");
    while(scanf("%d", &data) == 1)
    {
        insert_at_end(&head, data);        
    }

    printf("\nLinked List: ");
    display(head);
    
    getchar();
    
    printf("\nEnter k: ");
    scanf("%d", &k);

    printf("\nAfter rotation: ");
    head = rotate(head, k);
    
    display(head);
    
    return 0;
}