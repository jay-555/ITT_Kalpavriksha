#include <stdio.h>
#include<string.h>
#include <stdlib.h>


// function prototype
void calculate(float numstack[], int *ntop, char operstack[], int *optop);
int operatorprec(char ch);
int fractionPart(float num);
int is_digit(char);
int is_space(char);

// main function
int main(){

    char equ[100];
    int i;
    char ch;
   
// To keep track of numbers
float numstack[50];
int ntop = -1;

// To keep track of operators
char operstack[30];
int optop = -1;

printf("Enter the equation: ");
scanf("%[^\n]", equ);
equ[strcspn(equ, "\n")] = 0;  

    for(i = 0; i < strlen(equ); i++)
    {
        ch = equ[i];
        if(is_space(ch))
        {
            continue;
        }
        if (is_digit(ch)) 
        {
            float num = 0;
            while (i < strlen(equ) && is_digit(equ[i])) 
            {
                num = num * 10 + (equ[i] - '0');
                i++;
            }
            numstack[++ntop] = num; //push number
            i--;
        } 
        else if (ch == '/' || ch == '*' || ch == '+' || ch == '-') 
        {
            while (optop != -1 && operatorprec(ch) <= operatorprec(operstack[optop])) 
            {
                calculate(numstack, &ntop, operstack, &optop);
            }
            operstack[++optop] = ch; // Push operator
        } 
        else 
        {
            printf("Error: Invalid expression.\n");
            return 1;
        }
    }
    while (optop != -1)
    {
        calculate(numstack, &ntop, operstack, &optop);
    }
    if(ntop == 0)
    {
        // check result has some decemil value
        int check_result = fractionPart(numstack[0]);

        if (check_result == 1)
        {
            printf("Result: %0.2f\n", numstack[0]);
        }
        else if (check_result == 2)
        {
            printf("Result: %d\n", (int)numstack[0]);
        }
    } 
    else 
    {
        printf("Error: Invalid expression.\n");
    }
    return 0;   
}

// function to do calculation and 
void calculate(float numstack[], int *ntop , char operstack[], int *optop){
    float num1, num2, res;
    char op;
    num1 = numstack[(*ntop)--];
    num2 = numstack[(*ntop)--];
    op = operstack[(*optop)--];

    switch (op)
    {
    case '+':
        res = num2 + num1;
        break;
    case '-':
        res = num2 - num1;
        break;
    case '*':
        res = num2 * num1;
        break;
    case '/':
        if (num1 == 0)
        {
            printf("Error: Division by zero\n");
            exit(1);
        }
        res = num2 / num1;
        break;
    default: res = 0;
        printf("Error: Invalid expression.\n");
        exit(1);
    }
    numstack[++(*ntop)] = res;
}

// To check the order of the calculation (DMAS)
int operatorprec(char ch) {
    if (ch == '+' || ch == '-') 
    {
        return 1;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 0;
}

// check the fractional (if any) part of ans return 1 for fractinal part
int fractionPart(float num){
    float fraction_part = num - (int)num;
    if ((fraction_part) > 0.000001 || fraction_part < -0.000001)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

// check digit 
int is_digit(char c)
{
    if(c >= '0' && c <= '9')
    {
        return 1;
    }
    else return 0;
}

// check space
int is_space(char c)
{
    if (c == ' ')
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}