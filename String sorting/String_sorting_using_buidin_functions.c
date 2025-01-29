/*
INPUT: "hi heloo hey"
OUTPUT: hello, hey, hi
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char**)b);
}


void printarr(char *sen[20],int index)
{
    for(int i = 0; i < index; i++)
    {
        if(i != 0) printf(", ");
        printf("%s", sen[i]);
    }
    printf("\n");
}

int main()
{
    char input[100];

    fgets(input , sizeof(input), stdin);

    if(input[strlen(input) - 1] == '\n')
    {
        input[strlen(input) - 1] = '\0';
    }

    char *word = strtok(input, " ");
    int index = 0;
    char *sen[20];

    while(word != NULL)
    {
        sen[index++] = word;
        word = strtok(NULL, " ");
    }

    printf("Before sorting: ");

    printarr(sen, index);

    qsort(sen, index, sizeof(char *), compare);

    printf("\nafter sorting: ");

    printarr(sen, index);

    return 0;
}