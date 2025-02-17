/*
9. Word Count in a Sentence
Problem:
Given a sentence, count the number of occurrences of each word using a hash map.

Input:
sentence = "to be or not to be"
Output:
to -> 2, be -> 2, or -> 1, not -> 1

Task:

Use the word as the key and its frequency as the value.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node
{
    char key[50];
    int val;
    struct Node* next;
} Node;

Node* HashTable[MAX];

void init()
{
    for(int i = 0; i < MAX; i++)
    {
        HashTable[i] = NULL;
    }
}


int hash(const char *key)
{
    int val = 0;
    
    for(int i = 0; i < strlen(key) ; i++) val = val  + key[i];
    
    return (val % MAX);
}


void count(const char *key)
{
    int idx = hash(key);
    
    if(HashTable[idx] != NULL)
    {
        Node*  temp = HashTable[idx];
        
        while(temp && strcmp(temp->key, key) != 0)
        {
            temp = temp->next;
        }
        
        if(temp != NULL)
        {
            temp->val++;
        }
    }
    
    else
    {
        Node* newnode = (Node*)malloc(sizeof(Node));
        strcpy(newnode->key, key);
        newnode->val = 1;
        newnode->next = NULL;
        
        if(HashTable[idx] == NULL)
        {
            HashTable[idx] = newnode;
        }
        else 
        {
            // insert at start
            newnode->next = HashTable[idx];
            HashTable[idx] = newnode;
        }
    }
}


int get(const char *key)
{
    int idx  = hash(key);
    
    Node* temp = HashTable[idx];
    
    while(temp != NULL && strcmp(temp->key, key) != 0)
    {
        temp = temp->next;
    }
    
    if(temp != NULL)
    {
        return temp->val;
    }
    
    return -1;
}

// printf

void display()
{
    for(int i = 0; i < MAX; i++)
    {
        Node* temp = HashTable[i];
        while(temp != NULL)
        {
            printf("(%s - %d) \n", temp->key, temp->val);
            temp  = temp->next;
        }
    }
}


int main()
{
    // printf("Hello World");
    
    init();
    
    char input[100];
    char string[100][100];
    
    fgets(input, sizeof(input), stdin);
    
    if(input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
    
    
    int ifword = 0;
    int word = 0;
    int charcount = 0;
    for(int i = 0; input[i] != '\0'; i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            ifword = 1;
            string[word][charcount++] = input[i];
        }
        else if(ifword && input[i] ==' ')
        {
            ifword = 0;
            string[word][charcount] = '\0';
            word++;
            charcount = 0;
        }
    }
    
    if(ifword)
    {
        string[word][charcount] = '\0';
    }
    
    for(int i = 0; i <= word; i++)
    {
        count(string[i]);
    }
    
    display();

    return 0;
}