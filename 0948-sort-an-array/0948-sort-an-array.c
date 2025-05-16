/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize) {
    int max = nums[0], min = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(min > nums[i]) min = nums[i];
        else if(max < nums[i]) max = nums[i];
    }
    int range = max - min;
    int count[range+1];
    int *ans = (int *)malloc(numsSize*sizeof(int));
    memset(count, 0, sizeof(count));
    for(int i = 0; i < numsSize; i++){
        count[nums[i]-min]++;
    }
    for(int i = 1; i <= range; i++){
        count[i] += count[i-1];
    }
    for(int i = numsSize-1; i >= 0; i--){
        ans[count[nums[i]-min]---1] = nums[i];
    }
    *returnSize = numsSize;
    return ans;
}