/*
Assignment-2:
Given an array of strings group the anagrams together. 
You can return the answer in any order.
 
Example 1:
Input: ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Explanation:
There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:
Input: [""]
Output: [[""]]
Example 3:
Input: ["a"]
Output: [["a"]]

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int parse_input(char *input, char string[10][10])
{
    int word_index = 0;
    int char_index = 0;
    int ifword = 0;
    
    for(int i = 0; input[i] != '\0' ; i++)
    {
        if(input[i] >= 'a' && input[i] <= 'z')
        {
            string[word_index][char_index++] = input[i];
            ifword = 1;
        }
        else if(ifword)
        {
            string[word_index][char_index] = '\0';
            word_index++;
            char_index = 0;
            ifword = 0;
        }
    }
    
    return word_index;
}


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
    free(arr);
    free(text_arr);
    return 1;
}

int anagrams(char string[10][10], char result[10][10][10], int *result_size, int size, int *width) {

    // check for each word
    for (int index = 0; index < size; index++) {
        int if_group = 0;


        for (int j = 0; j < *result_size; j++) {
            if (check_anagram(string[index], result[j][0])) {
                strcpy(result[j][width[j]], string[index]);  
                width[j]++;
                if_group = 1;
                break;
            }
        }
        
        if (!if_group) {
            strcpy(result[*result_size][0], string[index]); 
            width[*result_size] = 1;
            (*result_size)++;
        }
    }

    return 0;
}


int main()
{

    char input[100];
    char string[10][10];
    int result_size = 0;
    
    printf("Enter the stirng: ");
    fgets(input, sizeof(input), stdin);

    int len = parse_input(input, string);
    
    // result array
    char result[10][10][10];
    int width[10]; 
    
    anagrams(string, result, &result_size, len, width);
    

    printf("\nan array of strings group the anagrams together:\n");


    printf("[\n");
    for (int i = 0; i < result_size; i++) {
        printf("   [");
        for (int j = 0; j < width[i] && result[i][j][0] != '\0'; j++) {
            printf("\"%s\"", result[i][j]);
            if (j < width[i] - 1) 
            {
                printf(", ");
            }
        }
        printf("],\n");
    }
    printf("]\n");

    return 0;
}