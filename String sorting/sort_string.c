
/*
step 1: take input
step 2: convert it into 2d char string
step 3:

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int convert2d(char *input,char *sen[20])
{
    int word = 0;
    int char_len = 0;
    int ifword = 0;
    int index = 0;

    while (input[index] != '\0')        
    {
        if(input[index] >= 'a' && input[index] <= 'z')
        {
            if(ifword == 0)
            {
                sen[word] = (char*)malloc(100*sizeof(char));
                char_len = 0;
            }
            sen[word][char_len++] = input[index];
            ifword = 1;
        }
        else if((input[index] == ' ' || input[index] == ',' )&& ifword)
        {
            sen[word][char_len] = '\0';
            word++;
            ifword = 0;
        }
        index++;
    }

    if(ifword)
    {
        sen[word][char_len] = '\0';
        word++;
    }
    
    return word;  
}


void printsen(char *sen[20],int len)
{
    for(int i = 0; i < len; i++)
    {
        if(i != 0) printf(", ");
        printf("%s", sen[i]);
    }
    printf("\n");
}


// function to sort  the sentance
void sortsen(char *sen[20], int len)
{
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i+1; j < len; j++)
        {
            int size1 = strlen(sen[i]);
            int size2 = strlen(sen[j]);
            int index = 0;

            while(index < size1 && index < size2)
            {
                if(sen[i][index] > sen[j][index])
                {
                    char *temp = sen[i];
                    sen[i] = sen[j];
                    sen[j] = temp;
                    break;
                }
                index++;
            }
        }
    }
}


int main()
{
    char input[100];
    
    printf("Enter words seperated by space or comma: ");
    fgets(input, sizeof(input), stdin);

    if(input[strlen(input -1)] == '\n')
    {
        input[strlen(input) - 1] = '\0';
    }

    // convert it into 2d arr
    char *sen[30];
    
    int len = convert2d(input, sen);

    printf("Words before sorting: ");

    printsen(sen, len);

    sortsen(sen, len);

    printf("Words after sorting: ");

    printsen(sen, len);

    return 0;
}