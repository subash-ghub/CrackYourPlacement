974. Subarray Sums Divisible by K

int subarraysDivByK(int* nums, int numsSize, int K) {
    int* modCount = (int*)calloc(K, sizeof(int));
    int sum = 0;
    int result = 0;
    modCount[0] = 1;  // there's one way to have a sum of 0 which is the empty subarray

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        int mod = (sum % K + K) % K;  // handle negative mod results
        
        result += modCount[mod];
        modCount[mod]++;
    }

    free(modCount);
    return result;
}