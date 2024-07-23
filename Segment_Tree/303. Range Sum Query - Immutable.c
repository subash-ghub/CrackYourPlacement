typedef struct 
{
    int *prefixSums;
    int size;
} NumArray;
NumArray* numArrayCreate(int* nums, int numsSize) 
{
    NumArray* obj = (NumArray*)malloc(sizeof(NumArray));
    obj->prefixSums = (int*)malloc((numsSize + 1) * sizeof(int));
    obj->size = numsSize;
    obj->prefixSums[0] = 0;
    for (int i = 0; i < numsSize; i++) {
        obj->prefixSums[i + 1] = obj->prefixSums[i] + nums[i];
    }
    return obj;
}
int numArraySumRange(NumArray* obj, int left, int right) 
{
    return obj->prefixSums[right + 1] - obj->prefixSums[left];
}
void numArrayFree(NumArray* obj) 
{
    free(obj->prefixSums);
    free(obj);
}
