/*
Longest Substring with Exactly K Distinct Characters 
Problem Statement: 
Given a string s and an integer K, find the length of the longest substring that contains exactly K 
distinct characters. If no such substring exists, return -1. 
Input: 
• A string s of length N. 
• An integer K. 
Output: 
• An integer representing the length of the longest substring with exactly K distinct characters. 
Example: 
Input: s = "aabbcc", K = 2 
Output: 4 (aabb is the longest substring with exactly 2 distinct characters.) 
*/

#include <stdio.h>
#include <string.h>


int check_distint_char(char *sub,int size)
{
    char alph[26] = {0};

    int res = 0;

    for(int i = 0; i < size; i++)
    {
        alph[(sub[i] - 'a')]++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(alph[i] > 0)
        {
            res++;
        }
    }
    return res;
}

int distinct_character(char *input,int k)
{
    int n = strlen(input);
    int max = 0; // hold result

    for(int i = 0; i < n; i++)
    {
        char sub[n - i + 1];
        int idx = 0;

        for(int j = i; j < n; j++)
        {
            sub[idx++] = input[j];
            // printf("%s\n", sub);/
        }
        sub[idx] = '\0';

        // calcultation
        if(check_distint_char(sub, idx) == k)
        {
            int size = strlen(sub);
            if(size > max)
            {
                max = size;
            }
        }
        sub[0] = '\0';
    }

    return max;
}



int main()
{
    char input[100];
    int k;
    
    printf("Enter the character: ");
    scanf("%s", input);
    
    printf("Enter k: ");
    scanf("%d", &k);


    int ans = distinct_character(input, k);

    printf("%d", ans);
    return 0;
}