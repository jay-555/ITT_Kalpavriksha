/*

Given two strings s and t, return true if t is an 
anagram
 of s, and false otherwise.
 
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true
Example 2:
Input: s = "rat", t = "car"
              
Output: false

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_anagram(char *input, char *test)
{

    int *arr = (int*)calloc(26, sizeof(int));
    int *text_arr = (int*)calloc(26, sizeof(int));
    

    for(int start = 0; input[start] != '\0' ; start++)
    {
        int index = input[start] - 'a';
        arr[index]++;
    }
    
    for(int start = 0; test[start] != '\0' ; start++)
    {
        int index = test[start] - 'a';
        text_arr[index]++;
    }
    
    for(int counter = 0; counter < 26 ; counter++)
    {
        if(arr[counter] != text_arr[counter])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{

    char input[50];
    char test[50];

    printf("Enter input: ");

    scanf("%[^\n]", input);
    getchar();

    printf("Enter text: ");
    scanf("%[^\n]", test);

    int result = check_anagram(input, test);

    if(result)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
    return 0;
}