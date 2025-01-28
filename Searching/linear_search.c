
// Linear search
// time complexity: O(n)

#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int index = 0; index < size; index++) {
        if (arr[index] == target) {
            return index;  // return index if target is found
        }
    }
    return -1;  // return -1 if target is not found
}

int main()
{
    printf("This program is to demonstrate Linear search\n");

    int size, target;

    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int arr[size];

    for (int index = 0; index < size; index++) {
        scanf("%d", &arr[index]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    // Output
    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    return 0;
}