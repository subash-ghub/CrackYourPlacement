class Solution 
{
 public:
  vector<int> countSmaller(vector<int>& nums) 
{
    vector<int> ans(nums.size());
    const unordered_map<int, int> ranks = getRanks(nums);
    FenwickTree tree(ranks.size());

    for (int i = nums.size() - 1; i >= 0; --i) 
{
      const int num = nums[i];
      ans[i] = tree.get(ranks.at(num) - 1);
      tree.add(ranks.at(num), 1);
    }

    return ans;
  }
 private:
  unordered_map<int, int> getRanks(const vector<int>& nums) 
{
    unordered_map<int, int> ranks;
    set<int> sorted(nums.begin(), nums.end());
    int rank = 0;
    for (const int num : sorted)
      ranks[num] = ++rank;
    return ranks;
  }
};
