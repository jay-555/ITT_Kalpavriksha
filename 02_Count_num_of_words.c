/*
2.Problem Statement: 
Write a program to count the number of words in a given string. Assume words are separated 
by one or more spaces, and the string may contain leading or trailing spaces. 
Sample Input and Output: 
1. Input: "Hello World" 
Output: 2 
2. Input: " The quick brown fox" 
Output: 4 
3. Input: "This is a test " 
Output: 4 

*/

#include <stdio.h>
#include <stdlib.h>


int word_in_sentence(char *input)
{
    int ifword = 0;
    int count = 0;

    for(int index = 0; input[index] != '\0'; index++)
    {
        if((input[index] >= 'a' && input[index] <= 'z') || (input[index] >= 'A' && input[index] <= 'Z'))
        {
            ifword = 1;
        }
        else if(ifword && input[index] == ' ')
        {
            count++;
            ifword = 0;
        }
    }

    if(ifword)
    {
        count++;
    }

    return count;
}

int count_words()
{
    char input[100];

    printf("\nProgarm to count the number of words in sentence\n");
    printf("Enter the input: ");
    scanf("%[^\n]", input);

    printf("Entered stirng: %s\n", input);

    int size = word_in_sentence(input);

    printf("No of words: %d", size);
    return 0;
}

int main()
{
    count_words();

    return 0;
}