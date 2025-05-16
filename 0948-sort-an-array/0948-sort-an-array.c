#include <stdlib.h>
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int mn = INT_MAX, mx = INT_MIN;

    // Find min and max in array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < mn) mn = nums[i];
        if (nums[i] > mx) mx = nums[i];
    }

    int range = mx - mn + 1;
    int* freq = (int*)calloc(range, sizeof(int));  // initialize frequency array

    // Count frequency
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] - mn]++;
    }

    // Allocate result array
    int* result = (int*)malloc(numsSize * sizeof(int));
    int index = 0;

    // Reconstruct the sorted array
    for (int i = 0; i < range; i++) {
        while (freq[i]-- > 0) {
            result[index++] = i + mn;
        }
    }

    free(freq);  // cleanup
    *returnSize = numsSize;
    return result;
}
