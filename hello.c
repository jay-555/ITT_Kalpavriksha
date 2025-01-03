/*
Write a program to find the longest word in a given sentence.
Input: Hi Helo World, I am here.
Output: 5
*/ 


#include <stdio.h>
#include<string.h>
#include <ctype.h>

int find_largest_word(char sentence[])
{
    int size = strlen(str);
    int max = 0;
    int count = 0;
    int start = 0;
    
    for( start = 0; sentence[start] != '\0'; start++)
    {
        if(isalnum(sentence[start]))
        {
            count+=1;
        }
        else if (sentence[start] == ' ' || (!isalnum(sentence[start])))
        {
            if(count >= max)
            {
                max = count;
                count =0;
            }
        }
    } 
    // handling last element

    if(count > 0 && count > max && start < size)
    {
        max = count;
    }
    return max;
}


int main()
{
    char sentence[200];

    printf("Enter the string: ");

    fgets(sentence, sizeof(str), stdin);

    int large =  find_largest_word(sentence);

    printf("%d", large);
    return 0;
}