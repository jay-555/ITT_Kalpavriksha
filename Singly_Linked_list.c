// singly Linked list assignment
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
}node;


node* create(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next  = NULL;

    return temp;
}

void insertAtBeginning(node** head, int data)
{
    node* new_node = create(data);
    new_node->next = *head;
    *head = new_node;
    
}

void insertAtEnd(node** head, int data)
{
    node *new_node = create(data);
    
    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
    
    node* temp = *head;
    
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
}


void  insertAtPosition(node** head, int data, int pos)
{
    if(pos == 1)
    {
        insertAtBeginning(head, data);
    }
    
    node* new_node = create(data);
    
    node* temp = *head;
    while(pos > 2)
    {
        pos--;
        temp = temp->next;
    }
    
    new_node->next = temp->next;
    temp->next = new_node;
}

int display(node* head)
{
    if(head == NULL)
    {
        printf("List Empty\n");
        return 0;
    }
    node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}

void deleteAtBeginning(node** head)
{
    if(*head == NULL)
    {
        printf("List is empty;");
        return;
    }
    
    node* delete_node = *head;
    *head = (*head)->next;
    
    free(delete_node);
}

void deleteAtEnd(node** head)
{
    if(*head == NULL)
    {
        printf("List is empty:\n");
        return;
    }
    
    node* temp = *head;
    node* prev = NULL;
    
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    if(prev != NULL)
    {
        prev->next = NULL;
    }
    else
    {
        *head = NULL;
    }

    free(temp);
}

void  deleteAtPosition(node** head, int pos)
{
    if(pos == 1)
    {
        deleteAtBeginning(head);
        return;
    }
    
    node* temp = *head;
    node* prev = NULL;
    
    while(pos > 1 && temp != NULL)
    {
        pos--;
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL)
    {
        printf("position out of range.\n");
        return;
    }

    prev->next = temp->next;

    free(temp);
}


void updateAtPostition(node** head, int new_data, int pos)
{
    if(*head == NULL)
    {
        printf("Linked List is NULL");
        return;
    }
    
    node* temp = *head;
    
    while(pos > 1 && temp != NULL)
    {
        pos--;
        temp = temp->next;
    }
    
    if(temp != NULL)
    {
        temp->data = new_data;
    }
}


int single_linked_list()
{
    int input, operation;
    node* head = NULL;

    printf("Enter the number of operations: ");
    scanf("%d", &input);

    while (1)
    {

        printf("1. Add to the end\n");
        printf("2. Add to the beginning\n");
        printf("3. Add to the position\n");
        printf("4. Display\n");
        printf("5. Update elemet at position\n");
        printf("6. Delete the first element\n");
        printf("7. Delete the last element\n");
        printf("8. Delete the element at position\n");

        printf("Enter number for operation: ");
        scanf("%d", &operation);

        printf("\n");

        if(operation == 1)
        {
            input--;
            int data;
            printf("Enter the data to be insert at end: ");
            scanf("%d",&data);
            insertAtEnd(&head, data);
            
        }
        else if(operation == 2)
        {
            input--;
            int data;
            printf("Enter the data to be insert at beginning: ");
            scanf("%d",&data);
            insertAtBeginning(&head, data);
        }
        else if(operation == 3)
        {
            input--;
            int data, postition;

            printf("Enter the positon at which data is to be insert: ");
            scanf("%d", &postition);
            printf("Enter the data to be insert at end: ");
            scanf("%d",&data);
            insertAtPosition(&head, data, postition);
        }
        else if(operation == 4)
        {
            input--;
            printf("Output: ");
            display(head);
            printf("\n");
        }
        else if(operation == 5)
        {
            input--;
            int new_data, postition;
            printf("Enter the position to be updated: ");
            scanf("%d", &postition);
            printf("Enter the new data to be updated: ");
            scanf("%d", &new_data);
            updateAtPostition(&head, new_data, postition);
        }
        else if(operation == 6)
        {
            input--;
            deleteAtBeginning(&head);
        }
        else if(operation == 7)
        {
            input--;
            deleteAtEnd(&head);
        }
        else if(operation == 8)
        {
            input--;

            int position;
            printf("Enter the position to be deleted: ");
            scanf("%d", &position);
             deleteAtPosition(&head, position);
        }
        else
        {
            printf("Enter a valid operation");
        }

        if(input == 0)
        {
            break;
        }
    } 
}

// main driver function
int main()
{
    single_linked_list();

    return 0;
}