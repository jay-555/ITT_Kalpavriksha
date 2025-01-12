/*
1. Problem Statement: 
Write a program to remove all duplicate characters from a given string. The resulting string 
should retain the order of first appearance of characters and should not contain any duplicate 
letters. 
Sample Input and Output: 
1. Input: "programming" 
Output: "progamin" 
2. Input: "banana" 
Output: "ban" 
3. Input: "abacabad" 
Output: "abcd"

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int duplicate_char(char *input, char *result)
{
    int *hashmap = (int *)calloc(26, sizeof(int));
    int result_index = 0;

    for(int index = 0; input[index] != '\0' ; index++)
    {
        hashmap[input[index] - 'a'] += 1;
    }

    for(int index = 0; input[index] != '\0' ; index++)
    {
        if(hashmap[input[index] - 'a'] != 0)
        {
            result[result_index++] = input[index];
            hashmap[input[index] - 'a']  = 0;
        }
    }

    result[result_index] = '\0';

    return 0;
}

int find_duplicate()
{
    char input[100];
    char result[100];

    printf("\n\nProgram to remove Duplicate Characters from the string");

    printf("\nEnter the stirng: ");
    scanf("%[^\n]", input);

    printf("Enter string: %s", input);

    duplicate_char(input, result);


    printf("\nString with no duplication:  %s\n",result);

    return 0;
}

int main()
{
    find_duplicate();
    return 0;
}