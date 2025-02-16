// #hash table 
// key -> value (string -> int )

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10
// step 1. make a node 

typedef struct Node
{
    char key[50];
    int value;
    struct Node* next;
} Node;


// step 2. make an array of node (Hash Table)

Node* HashTable[MAX_SIZE];


// step 3. initialize all the nodes to NULL

void init()
{
    for(int i = 0;i < MAX_SIZE; i++)
    {
        HashTable[i] = NULL;
    }
}

// step 4. hash fuction

int hash(const char *key)
{
    unsigned int val = 0;
    
    for(int i = 0; i < strlen(key); i++)
    {
        val += key[i];
    }
    
    return (val % MAX_SIZE);
}


// step 5. make insert function

void insert(const char *key, int value)
{
    // create a node and move all the key value pair to that node 
    Node* newnode = (Node*)malloc(sizeof(Node));
    strcpy(newnode->key, key);
    newnode->value = value;
    newnode->next = NULL;
    
    // find index in HashTable using hash function
    
    int idx = hash(key);
    
    // if the block in table is pointing to Null that means the block is empty so no collesion point he block as new Node
    
    if(HashTable[idx] == NULL)
    {
        HashTable[idx] = newnode;
    }
    else
    {
        // else in calse of collision insert at first 
        newnode->next = HashTable[idx];
        HashTable[idx] = newnode;
    }
    
}

// search

int search(const char *key)
{
    // find idx
    int idx = hash(key);
    
    Node* temp = HashTable[idx];
    
    while(temp != NULL)
    {
        if(strcmp(temp->key, key) == 0)
        {
            return (temp->value);
        }
        temp = temp->next;
    }
    
    // key value not found
    return -1;
}


// delete 

void deleteKey(const char *key)
{
    int idx = hash(key);
    
    Node* temp = HashTable[idx];
    Node* prev = NULL;
    
    while(temp != NULL && (strcmp(temp->key, key) != 0))
    {
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL)
    {
        printf("key node found\n");
        return;
    }

    
    if(prev == NULL)
    {    
    // if it is first element is to be deleted
        HashTable[idx] = temp->next;
    }
    else
    {
        // node to be deleted is mid or end ;
        prev->next = temp->next;
    }
    
    free(temp);
    
    printf("deletee: %s", key);
}


// print all HashTable

void display()
{
    for(int i = 0; i <  MAX_SIZE; i++)
    {
        printf("[Slot %d] ",i );
        
        Node* temp = HashTable[i];
        
        while( temp != NULL)
        {
            printf("(%s - %d) ->", temp->key , temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


int main()
{
    // printf("Hello World");
    
        // Test insert
    insert("Alice", 25);
    insert("Bob", 30);
    insert("Charlie", 35);
    insert("Alice", 40); // Collision with "Alice" handled

    // Test display
    printf("\nHash Table:\n");
    display();

    //  search
    printf("\nSearch for 'Alice': %d\n", search("Alice"));
    printf("Search for 'David': %d\n", search("David"));

    // delete
    deleteKey("Bob");
    printf("\nHash Table after deleting 'Bob':\n");
    display();
    

    return 0;
}