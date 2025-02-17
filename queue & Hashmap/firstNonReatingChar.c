// Input: s = "aabcbddce"
// Output: ['a', -1, 'b', 'b', 'b', 'd', 'd', 'c', -1]
// Explanation:



// first non repeating char 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char queue[100];
int rear = -1, front = -1;

void enqueue(char ch)
{
    if(rear == 99)
    {
        return;
    }
    
    if(front == -1) front = 0;
    queue[++rear] = ch;
}


char dqueue()
{
    if(front == -1)
    {
        return '\0';
    }
    
    char data = queue[front];
    
    if(rear == front)
    {
        rear = -1, front = -1;
    }
    else
    {
        front++;
    }
    
    return data;
}



int main()
{
    // printf("Hello World");
    char input[100];
    int *hash = (int*)calloc(26, sizeof(int));


    
    scanf("%s", input);
    
    int len = strlen(input);
    
    
    for(int i = 0; i < len; i++)
    {
        char ch = input[i];
        
        enqueue(ch);

        hash[ch - 'a']++; 
        while(front != -1 && hash[queue[front] - 'a'] != 1)
        {
            dqueue();
        }
        
        if(front == -1)
        {
            printf("%d  ", -1);            
        }
        else
        {
            printf("%c ", queue[front]);
        }
    }

    return 0;
}