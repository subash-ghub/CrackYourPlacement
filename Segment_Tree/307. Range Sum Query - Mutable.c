typedef struct 
{
    int* tree;
    int n;
} NumArray;
void buildTree(int* tree, int* nums, int node, int start, int end) 
{
    if (start == end) {
        tree[node] = nums[start];
    } else {
        int mid = (start + end) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;
        buildTree(tree, nums, left_child, start, mid);
        buildTree(tree, nums, right_child, mid + 1, end);
        tree[node] = tree[left_child] + tree[right_child];
    }
}
void updateTree(int* tree, int node, int start, int end, int idx, int val) 
{
    if (start == end) 
{
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;
        if (idx <= mid) {
            updateTree(tree, left_child, start, mid, idx, val);
        } else {
            updateTree(tree, right_child, mid + 1, end, idx, val);
        }
        tree[node] = tree[left_child] + tree[right_child];
    }
}
