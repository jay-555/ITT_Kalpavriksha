/*
5. Problem Statement: 
Write a program to implement the atoi() function, which converts a string to an integer. The 
function should handle negative numbers and return 0 for invalid input. 
Sample Input and Output: 
1. Input: "1234" 
Output: 1234 
2. Input: "-567" 
Output: -567 
3. Input: "abc123" 
Output: 0 
*/

#include <stdio.h>

int process(const char *input)
{
    int neg = 0;
    int num = 0;
    int index = 0;

    while(input[index] == ' ')
    {
        index++;
    }

    if(input[index] == '-')
    {
        neg = 1;
        index++;
    }

    while(input[index] >= '0' && input[index] <= '9')
    {
        num = 10*num + (input[index] - '0');
        index++;
    }

    if(neg)
    {
        num = -num;
    }
    return num;
}

int xatoi()
{
    char input[100];

    printf("\n\nProgram to implement atoi() function\n");

    printf("Enter the input string: ");
    scanf("%[^\n]", input);

    int num = process(input);

    printf("%d", num);
}


int main()
{
    xatoi();
}