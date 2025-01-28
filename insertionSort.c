
//  Insertion sort

#include<stdio.h>

void insertionsort(int arr[], int n){
    for(int counter1=0; counter1 < n ; counter1++){
        int key = arr[counter1];
        int counter2 = counter1-1;
        
        while (counter2 >= 0 && arr[counter2] > key){
            arr[counter2 + 1] = arr[counter2];
            counter2--;
        }
        
        arr[counter2 + 1] = key;
    }
}

void printarray(int *arr, int size)
{
    for(int index = 0; index  < size; index++)
    {
        printf("%d ", arr[index]);
    }
    printf("\n");
}

int main()
{
    printf("This program is to implement Insertion sort on array\n");

    int size, target;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    for (int index = 0; index < size; index++) {
        scanf("%d", &arr[index]);
    }

    printf("Array before sorting: ");
    printarray(arr, size);

    insertionsort(arr, size);

    printf("Array after sorting: ");
    printarray(arr, size);

    return 0;
}