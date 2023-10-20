int removeDuplicates(int* nums, int numsSize){
    int * temp = (int *)malloc(sizeof(int)*numsSize);
    int idx1 = 0; int idx2 = 0;
    for(idx1=0;idx1<numsSize;idx1++){
        if(idx1==0||nums[idx1]!=nums[idx1-1]) {temp[idx2++] = nums[idx1];printf("%d\n",nums[idx1]);}
    }
    for(idx1=0;idx1<idx2;idx1++)nums[idx1] = temp[idx1];
    return idx2;
}