// Longest Substring Without Repeating Characters

/*

Example Input and Output
Example 1:
Input: abcabcbb
Output: (True, {Length: 3, Substring: abc})

Example 2:
Input: bbbbb
Output: (True, {Length: 1, Substring: b})

Example 3:
Input: pwwkew
Output: (True, {Length: 3, Substring: wke})


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int queue[MAX];
int rear = -1;
int front  = -1;


void enqueue(int data)
{
    if(rear == MAX - 1)
    {
        return;
    }
    
    if(front == -1) front = 0;
    
    queue[++rear] = data;
}

char dqueue()
{
    if(front == -1)
    {
        return -1;
    }
    
    char data = queue[front];
    
    if(rear == front)
    {
        rear = -1;
        front = -1;
    }
    else 
    {
        front += 1;
    }
    return data;
}

int size()
{
    if(front == -1)
    {
        return 0;
    }
    
    return (rear - front + 1);
}



int main()
{
    int *hash = (int *)calloc(26, sizeof(int));
    
    char input[MAX];
    
    scanf("%s", input);
    
    int len = 0;
    
    char sub[MAX];
    int idx = 0;
    
    for(int i = 0; input[i] != '\0' ; i++)
    {
        char ch = input[i];
        
        enqueue(ch);
        hash[ch - 'a']++;
        
        while(size() > 1 && (hash[ch - 'a'] > 1))
        {
            hash[queue[front] - 'a']--;
            dqueue();
        }
        
        if(size() > len)
        {
            len = size();
            idx = 0;
            for(int i = front; i <= rear; i++)
            {
                sub[idx++] = queue[i];
                
            }
        }
    }
    
    sub[idx] = '\0';
    
    printf("(True, {Length: %d, Substring: %s})\n", len, sub);
    
    return 0;
}