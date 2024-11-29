#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>

// function prototype
void calculate(float numstack[], int *ntop, char operstack[], int *optop);
int operatorprec(char ch);

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
fgets((equ), sizeof(equ), stdin);
equ[strcspn(equ, "\n")] = 0;  

    for(i = 0; i < strlen(equ); i++)
    {
        ch = equ[i];

        if(isspace(ch))
        {
            // i++;
            continue;
        }
        if (isdigit(ch)) {
            float num = 0;
            while (i < strlen(equ) && isdigit(equ[i])) {
                num = num * 10 + (equ[i] - '0');
                i++;
            }
            
            numstack[++ntop] = num; //push number
            i--;

            } else if (ch == '/' || ch == '*' || ch == '+' || ch == '-') 
            {
                while (optop != -1 && operatorprec(ch) <= operatorprec(operstack[optop])) {
                    calculate(numstack, &ntop, operstack, &optop);
            }
            operstack[++optop] = ch; // Push operator
        } else {
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
            printf("Result: %0.2f\n", numstack[0]);
        } else {
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
            printf("\nError: Division by zero\n");
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