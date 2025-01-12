/*
.Problem Statement: 
Write a program to check if one string is a rotation of another string. For example, "abcd" and 
"dabc" are rotations of each other. 
Sample Input and Output: 
1. Input: string1 = "abcd", string2 = "dabc" 
Output: true 
2. Input: string1 = "rotation", string2 = "ationrot" 
Output: true 
3. Input: string1 = "hello", string2 = "world" 
Output: false 
*/

#include <stdio.h>
#include <string.h>

int check_rotation(const char *string1, const char *string2)
{
    int len1 = strlen(string1);
    int len2 = strlen(string2);

    if(len1 != len2)
    {
        return 0;
    }

    for(int i = 0; i < strlen(string1) ; i++)
    {
        int match = 1;
        for(int j  = 0 ; j < len1 ; j++)
        {
            if(string1[(i+j) % len1] != string2[j])
            {
                match = 0;
                break;
            }
        }
        if(match)
        {
            return 1;
        }
    }
    return 0;
}

int Check_if_string_is_a_rotation_of_another()
{
    char string1[100];
    char string2[100];

    printf("Enter the first string: ");
    scanf("%[^\n]", string1);

    getchar();

    printf("Enter the second string: ");
    scanf("%[^\n]", string2);

    if(check_rotation(string1, string2))
    {
        printf("true\n");
    }
    else{
        printf("false\n");
    }

    return 0;
}

int main()
{
    Check_if_string_is_a_rotation_of_another();
    return 0;
}