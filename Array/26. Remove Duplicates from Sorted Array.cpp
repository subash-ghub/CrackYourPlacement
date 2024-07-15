class Solution 
{
 public:
  int removeDup(vector<int>& numbs) 
{
    int i = 0;
    for (const int num : numbs)
      if (i < 1 || num > numbs[i - 1])
        numbs[i++] = num;
    return i;
  }
};
