#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// size of a name limited to 50
#define MAX_NAME_LENGTH 50 


int is_valid(int rows, int columns)
{
    if (rows < 1 || rows > 10 || columns < 1 || columns > 10) 
    {
        printf("Invalid input for rows or columns. \
        Please ensure 1 <= rows <= 10 and 1 <= columns <= 10.\n");
        return 0;
    }
    return 1;
}

int is_vowel(char *name)
{
    char temp = tolower(name[0]);
    if(temp =='a' || temp =='e' || temp =='i' || temp == '0' || temp =='u')
    {
        return 1;
    }
    return 0;
}

int print_names_in_array(char **names, int rows, int columns)
{
    printf("The 2D array of names is: \n");

    for(int counter1 = 0; counter1 < rows; counter1++)
    {
        for(int counter2 = 0; counter2 <  columns; counter2++)
        {
            printf("%0.10s ", names[counter1 * columns + counter2]);
        }
        printf("\n");
    }
    return 0;
}


int longest_name(char **names, int rows, int columns, char *largest_name)
{
    int largest = 0;

    for(int counter1 = 0; counter1 < rows; counter1++)
    {
        for(int counter2 = 0; counter2 <  columns; counter2++)
        {
            if(strlen(names[counter1 * columns + counter2]) > largest)
            {
                largest = strlen(names[counter1 * columns + counter2]);
                strcpy(largest_name, names[counter1 * columns + counter2]);
            }
        }
    }

    return largest;
}


int name_start_with_vowel(char **names,int rows,int columns)
{
    int count = 0;
    
    for(int counter1 = 0; counter1 < rows; counter1++)
    {
        for(int counter2 = 0; counter2 <  columns; counter2++)
        {
            char *temp = names[counter1 * columns + counter2];
            if(is_vowel(temp))
            {
                count++;
            }
        }
    }
    return count;
}

int two_D_array()
{
    int rows, columns, valid = 0;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    
    printf("Enter number of colums: ");
    scanf("%d", &columns);
    
    if(!is_valid(rows, columns))
    {
        return 1;
    }

    // char names[rows][columns][MAX_NAME_LENGTH];
    char **names = (char**)malloc((rows*columns) * sizeof(char *));

    for(int cnt = 0; cnt < rows*columns ;cnt++)
    {
        names[cnt] = (char*)malloc(MAX_NAME_LENGTH* sizeof(char));
    }

 // input names
    

    printf("Enter the names: \n");
    for(int counter1 = 0; counter1 < rows; counter1++)
    {
        for(int counter2 = 0; counter2 <  columns; counter2++)
        {
            printf("Name at (%d,%d):", counter1, counter2);
            scanf("%s", names[counter1 * columns + counter2]);
        }
    }

    //print name

    print_names_in_array(names, rows, columns);


    // count and display number of names start with vowel

    int vowel_count = name_start_with_vowel(names, rows, columns);
    printf("\nNumaber of names starting with a vowel: %d\n", vowel_count);

    char largest_name[MAX_NAME_LENGTH];

    longest_name(names, rows, columns, largest_name);
    printf("The longest name: %s", largest_name);

    return 0;
}


// Driver main function
int main()
{
    two_D_array();
    return 0;
}