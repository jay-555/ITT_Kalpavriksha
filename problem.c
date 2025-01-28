

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* prev;
    struct node* next;
}node;

node* create(int data)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    
    return temp;
}


node* merge(node* left, node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;


    if (left->data < right->data) {
        left->next = merge(left->next, right);
        if (left->next != NULL) {
            left->next->prev = left;
        }
        left->prev = NULL;
        return left;
    } else {
        right->next = merge(left, right->next);
        if (right->next != NULL) {
            right->next->prev = right;
        }
        right->prev = NULL;
        return right;
    }
}


node* split(node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }

    node* fast = head;
    node* slow = head;


    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    node* second_half = slow->next;
    slow->next = NULL; 
    if (second_half != NULL) {
        second_half->prev = NULL; 
    }

    return second_half;
}

node* mergesort(node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    node* second_half = split(head);


    head = mergesort(head);
    second_half = mergesort(second_half);


    return merge(head, second_half);
}


node* insert_at_end(node** head, int data)
{
    node* new_node = create(data);
    
    if(*head == NULL)
    {
        *head = new_node;
        return new_node;
    }
    
    node* temp = *head;
    
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = new_node;
    new_node->prev = temp;
    
    return *head;
}

node* insert_at_beginning(node** head, int data)
{
    node* new_node = create(data);
    
    if(*head == NULL)
    {
        *head = new_node;
        return (*head);
    }
    
    new_node->next = *head;
    if(*head != NULL)
    {
        (*head)->prev = new_node;
    }
    
    return new_node;
}


node* insert_at_position(node** head, int data, int pos)
{
    if(pos == 1)
    {
        *head = insert_at_beginning(head, data);
        return *head;
    }
    
    node* temp = *head;
    
    for(int i = 1 ; i < pos && temp != NULL ; i++)
    {
        temp = temp->next;
    }
    
    if(temp == NULL)
    {
        printf("Positon out of bououds.\n");
        return *head;
    }
    
    node* new_node = create(data);
    
    temp->next = new_node;
    new_node->prev = temp;
    
    new_node->next = temp->next;
    

    if(new_node->next != NULL)
    {
        new_node->next->prev = new_node;    
    }
    return *head;
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        if(temp->next != NULL)
        {
            printf("<->");
        }
        temp  = temp->next;
    }
    printf("\n");
}


node* rotate(node* head, int k)
{
    node* temp = head;
    int len = 1;     
    
    while(temp->next != NULL)
    {
        len++;
        temp = temp->next;
    }
    
    k %= len; 
    
    if(k == 0)
    {
        return head;
    }
    
    temp->next = head; 
    head->prev = temp;

    temp = head;
    
    for(int i = 1; i < k; i++)  
    {
        temp = temp->next;
    }
    
    head = temp->next;    
    head->prev = NULL;     
    temp->next = NULL;

    return head;
}


node* reverse(node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node* prev_node = NULL;
    node* cur_node = head;

    while(cur_node != NULL)
    {

        // swap prev and next ptr of a node using the prev_node pointer
        prev_node = cur_node->prev;
        cur_node->prev = cur_node->next;
        cur_node->next = prev_node;

        // move cur to next node (here prev is next node because we have swaped the next and prev pointer)
        cur_node = cur_node->prev;
    }

    return prev_node->prev;
}


int search(node* head, int key) {
    node* temp = head;
    
    while (temp != NULL) {
        if (temp->data == key) {
            return 10; 
        }
        temp = temp->next;
    }
    return -1;
}


int main()
{
    node *head = NULL;

    printf("1. insert_at_beginning\n");
    printf("2. insert_at_position\n");
    printf("3. insert_at_end\n");
    printf("4. Print Linked List\n");
    printf("5. rotate linked List: \n");
    printf("6. Reverse \n");
    printf("7. Sort Linked List\n");
    printf("8. Search in Linked List");
    printf("\nEnter the operation: ");

    int operation;
    
    while(scanf("%d",&operation) == 1)
    {
        
        if(operation == 1)
        {
            int data;
            printf("Enter data to insert at beginning: ");
            scanf("%d", &data);
            
            head = insert_at_beginning(&head, data);
        }
        else if(operation == 2)
        {
            int pos;
            int data;
            printf("Enter the Positon: ");
            scanf("%d", &pos);
            printf("Enter data to insert at Positon: ");
            scanf("%d", &data);
            
            head = insert_at_position(&head, data, pos);
        }
        else if(operation == 3)
        {
            int data;
            printf("Enter data to insert at end: ");
            scanf("%d", &data);
            
            head = insert_at_end(&head, data);
        }
        else if(operation == 4)
        {
            printf("Linked List: ");
            display(head);
        }
        else if(operation == 5)
        {
            printf("Enter K: ");
            int k;
            scanf("%d", &k);
            head = rotate(head, k);
        }
        else if(operation == 6)
        {
            head = reverse(head);
        }
        else if(operation == 7)
        {
            // printf("Sorted ")
            head = mergesort(head);
            printf("Linked List is sorted\n");
        }
        else if (operation == 8)
        {
            int target;
            printf("Enter element to search in linked list: ");
            scanf("%d", &target);
            int ans = search(head, target);
            if(ans > 0)
            {
                printf("\n%d is present in Linked List\n");
            }
            else
            {
                printf("\n%d is present in Linked List\n");
            }
        }
        else
        {
            break;
        }
        printf("\nEnter the operation: ");
    }
    return 0;
}