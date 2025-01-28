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
    printf("This program is to demonstrate Selection Sort\n");

    int size, target;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    for (int index = 0; index < size; index++) {
        scanf("%d", &arr[index]);
    }

    printf("Array before sorting: ");
    printarray(arr, size);

    selectionsort(arr, size);

    printf("Array after sorting: ");
    printarray(arr, size);

    return 0;
}