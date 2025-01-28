#include<stdio.h>

int merge(int arr[], int start, int mid, int end){
    int size1 = mid - start + 1;
    int size2 = end - mid;
    
    int arr1[size1], arr2[size2];
    
    for(int counter1 = 0; counter1 < size1; counter1++){
        arr1[counter1] = arr[start + counter1];
    }
    
    for(int counter2 = 0; counter2 < size2; counter2++){
        arr2[counter2] = arr[mid + 1 + counter2];
    }
    
    int counter1=0, counter2=0, counter3=start;
    
    while(counter1 < size1 && counter2 < size2){
        if (arr1[counter1] <= arr2[counter2]){
            arr[counter3] = arr1[counter1];
            counter1++;
        }
        else{
            arr[counter3] = arr2[counter2];
            counter2++;
        }
        counter3++;
    }
    while (counter1 < size1){
        arr[counter3] = arr1[counter1];
        counter1++;
        counter3++;
    }
    return 0;
    
}

int mergesort(int arr[], int start, int end){
    if (start < end){
        int mid = start + (end - start) / 2;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    return 0;
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
    printf("This program is to implement MergeSort on array\n");

    int size, target;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    for (int index = 0; index < size; index++) {
        scanf("%d", &arr[index]);
    }

    printf("Array before sorting: ");
    printarray(arr, size);

    mergesort(arr, 0, size);

    printf("Array after sorting: ");
    printarray(arr, size);

    return 0;
}