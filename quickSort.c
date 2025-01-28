
//  Quick sort

#include <stdio.h>


int partition(int *arr, int low, int high) {
    int pivot = arr[high];  
    int i = low - 1; 

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
   
        int pi = partition(arr, low, high);

        
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
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
    printf("This program is to implement Quick sort on array\n");

    int size, target;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    for (int index = 0; index < size; index++) {
        scanf("%d", &arr[index]);
    }

    printf("Array before sorting: ");
    printarray(arr, size);

    quicksort(arr,0, size);

    printf("Array after sorting: ");
    printarray(arr, size);

    return 0;
}