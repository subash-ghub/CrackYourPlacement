int* findDuplicates(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) 
    {
        int index = abs(nums[i]) - 1;
        if (nums[index] < 0) {
            (*returnSize)++;
        }
        nums[index] = -nums[index];
    }
    int* result = (int*)malloc(*returnSize * sizeof(int));
    int j = 0;
    for (int i = 0; i < numsSize; i++) 
    {
        if (nums[abs(nums[i]) - 1] > 0) 
        {
            result[j++] = abs(nums[i]);
        }
    }

    return result;
}