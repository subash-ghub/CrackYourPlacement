int removeDuplicates(int* nums, int numsSize) 
{
    if (numsSize == 0) 
{
        return 0;
    }
    int UI = 0;
    for (int i = 1; i < numsSize; i++) 
{
        if (nums[i] != nums[UI]) 
{
            UI++;
            nums[UI] = nums[i];
        }
    }
    return UI + 1;
}
