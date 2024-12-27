#include <stdio.h>

int pattern(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for (int  col = 1; col <= row ; col++)
        {
            printf("%d", col);
        }

        // space
        for(int space = 1; space <= 2*(n-row) ; space++)
        {
            printf(" ");
        }

        for(int col = row; col >= 1;  col--)
        {
            printf("%d", col);
        }
        printf("\n");
    }

// for lower half
    for (int row = 1; row < n ; row++)
    {
        // left most part
        for (int  col = 1 ; col <= n - row; col++)
        {
            printf("%d", col);
        }

        // space
        for(int space = 1 ; space <= 2*row ; space++)
        {
            printf(" ");
        }

        // Right most part
        for(int col = n - row ; col >= 1;  col--)
        {
            printf("%d", col);
        }
        printf("\n");
    }
    return 0;
}

// Driver
int main()
{
    int row;
    printf("Enter the number of rows: ");
    scanf("%d", &row);
    printf("\n\n\n");
    pattern(row);
    return 0;
}