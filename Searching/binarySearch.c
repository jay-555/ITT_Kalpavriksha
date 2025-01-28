// Binary search 
// time complexity: O(log(n))

#include <stdio.h>

int binarysearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        if (arr[mid] == target) {
            return mid;  
        }
        else if (arr[mid] < target) {
            low = mid + 1;  
        }
        else {
            high = mid - 1;  
        }
    }
    return -1; 
}

int main()
{
    printf("This program is to demonstrate Binary Search\n");

    int size, target;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    for (int index = 0; index < size; index++) {
        scanf("%d", &arr[index]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = binarysearch(arr, size, target);

    // Output
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    return 0;
}