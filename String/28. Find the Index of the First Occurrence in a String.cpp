class Solution 
{
 public:
  int strStr(string hs, string nd) 
{
    const int m = hs.length();
    const int n = nd.length();
    for (int i = 0; i < m - n + 1; i++)
      if (hs.substr(i, n) == nd)
        return i;
    return -1;
  }
};
