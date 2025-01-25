/**
 * 
 * Given an array of distinct integers candidates and a target integer target, 
 * print all combinations of candidates where the chosen 
 * numbers sum to target. You may return the combinations in any order.
 
The same number may be chosen from candidates an unlimited number of times.
 
Example 1:
 
Input: candidates = [2,3,6,7], target = 7
Output: 2 2 3 
	      7
 
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
 
 
Example 2:
Input: candidates = [2,3,5], target = 8
Output: 2 2 2 2
	      2 3 3
	      3 51
 
Example 3:
 
Input: candidates = [2], target = 1
Output: 
 */


#include <stdio.h>

void find_target(int *arr, int *output, int target, int size, int index, int *outindx) {
    // base case
    if (target == 0) {
        for (int i = 0; i < *outindx; i++) {
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
    }

    if (index >= size) {
        return;
    }

    if (arr[index] <= target) {
        output[(*outindx)++] = arr[index];
        find_target(arr, output, target - arr[index], size, index, outindx); 
        (*outindx)--; 
    }

    find_target(arr, output, target, size, index + 1, outindx);
}


int main() {
    // int arr[] = {2, 3, 6, 7};
    int arr[20];
    int num, index = 0;
    int target;


    printf("Enter the array: ");

    while (scanf("%d", &num) == 1)
    {
        arr[index++] = num;
    }

    getchar();

    printf("Enter the target: ");
    scanf("%d", &target);
    
    int size = sizeof(arr) / sizeof(arr[0]);
    int output[100]; 
    int outindx = 0;  

    find_target(arr, output, target, size, 0, &outindx);

    return 0;
}
