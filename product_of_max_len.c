// Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.
 
 
// Example 1:
 
// Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16
// Explanation: The two words can be "abcw", "xtfn".
// Example 2:
 
// Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4
// Explanation: The two words can be "ab", "cd".
// Example 3:
 
// Input: words = ["a","aa","aaa","aaaa"]
// Output: 0
// Explanation: No such pair of words.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(char *a, char* b)
{
    int hash1[26] = {0};
 
    for(int i = 0; i < strlen(a); i++)
    {
        char idx = a[i];
        hash1[idx - 'a']++;
    }


    for(int j = 0; j < strlen(b); j++)
    {
        char ch = b[j];
        if((hash1[ch - 'a']) >= 1)
        {
            return -1;
        }
    }

    return 1;
}


int main()
{
    // char arr[10][10] = {"abcw","baz","foo","bar","xtfn","abcdef"};

    char arr[100][100];

    int num;
    printf("Enter the number of words : ");
    scanf("%d", &num);

    for(int i = 0; i < num; i++)
    {
        printf("Enter %d word: ", i+1);
        scanf("%s", arr[i]);
    }

    int max = 0;

    for(int i = 0; i < num; i++)
    {
        //compare 2 words check
        for(int j = i+1; j < num; j++)
        {
            int value = compare(arr[i], arr[j]);
            if(value == -1)
            {
                continue;
            }
            else
            {
                // printf("%s -- %s\n", arr[i], arr[j]);
                int wordlen = (strlen(arr[i])) * (strlen(arr[j]));
                if( wordlen > max)
                {
                    max = wordlen;
                }
                
            }
        }
    }

    printf("%d", max);

    return 0;
}