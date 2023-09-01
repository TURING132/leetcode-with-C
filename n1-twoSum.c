/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int * result = (int*)malloc(sizeof(int)*2);
    *returnSize = 0;
    int i,j;
    for (i=0;i<numsSize;i++){
        int a = nums[i];
        for (j = i+1;j<numsSize;j++){
            int b = nums[j];
            if(a+b == target){
                result[0] = i; result[1] = j;
                *returnSize = 2;
            }
        }
    }
    return result;
}