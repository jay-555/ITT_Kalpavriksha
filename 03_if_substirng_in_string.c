/*
3.Problem Statement: 
Write a function to check if a given substring exists within a string. Return the starting index of 
the substring if it exists; otherwise, return -1. 
Sample Input and Output: 
1. Input: string = "hello world", substring = "world" 
Output: 6 
2. Input: string = "programming", substring = "gram" 
Output: 3 
3. Input: string = "abcdef", substring = "xyz" 
Output: -1 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_substring(const char *string, const char *substring)
{
    int string_len = strlen(string);
    int sub_string_len = strlen(substring);

    for(int i = 0; i <= (string_len - sub_string_len) ; i++)
    {
        int j = 0;
        while(j < sub_string_len && string[i+j] == substring[j])
        {
            j++;
        }
        if(j == sub_string_len)
        {
            return i;
        }
    }
    return -1;
}

int check_substring_in_string()
{
    char string[100], substring[100];

    printf("Enter the string: ");
    scanf("%[^\n]", string);
    getchar();

    printf("Etner the substring: ");
    scanf("%[^\n]", substring);
    getchar();

    int result = check_substring(string, substring);

    if(result != -1)
    {
        printf("Substring found at index: %d\n", result);
    }
    else
    {
        printf("Substring is not found: %d\n", -1);
    }

    return 0;
}


int main()
{
    check_substring_in_string();

    return 0;
}