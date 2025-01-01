/*
Write a program in C to calculate the result of the mathematical BN % M, where the values of
the base B, the exponent N, and the modulus M are provided as input by the user. The
program should print the output of the expression and handle large values of N efficiently
without causing overflow.
*/ 


#include <stdio.h>

double solution(int base, int power, int mod)
{
    long long ans = 1;
    long long base_mod = base % mod;

    while (power > 0)
    {
        if(power % 2 == 1)
        {
            ans = (ans * base_mod) % mod;
            power--;
        }
        else{
            base_mod = (base_mod * base_mod) % mod;
            power = power/2;
        }
    }
    return ans;
}

int mathematical_expression()
{
    int base, power, mod;
    int flag = 1;
    
    while(flag)
    {
        printf("Enter the base: ");
        scanf("%d", &base);

        printf("Enter the Power: ");
        scanf("%d", &power);
    
        printf("Enter the Modulus: ");
        scanf("%d", &mod);

        if(mod > 0 && power >= 0 && base >= 0)
        {
            flag = 0;
        }
        else
        {
            printf("\n You Entered Invalid Input Please try again\n");
        }
    }

    // call funcion
    int ans = solution(base, power, mod);
    
    printf("%d", ans);
}
int main()
{
    mathematical_expression();
return 0;
}