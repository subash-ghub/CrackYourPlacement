int* twoSum(int* num, int numsize, int target, int* returnsize) {
    *returnsize = 2;
    int* ans = (int*)malloc(*returnsize * sizeof(int));
    for(int i = 0; i < numsize; i++) {
        for(int j = i + 1; j < numsize; j++) {
            if(num[i] + num[j] == target) {
                ans[0] = i;
                ans[1] = j;
                return ans;
            }
        }
    }
    *returnsize = 0;
    return NULL;
}
