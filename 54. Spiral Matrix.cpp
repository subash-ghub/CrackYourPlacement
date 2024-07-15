class Solution 
{
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    if (matrix.empty())
      return {};
    const int m = matrix.size();
    const int n = matrix[0].size();
    vector<int> ans;
    int a = 0;
    int b = 0;
    int c = m - 1;
    int d = n - 1;
    while (ans.size() < m * n) 
{
      for (int j = a; j <= d && ans.size() < m * n; ++j)
        ans.push_back(matrix[b][j]);
      for (int i = b + 1; i <= c - 1 && ans.size() < m * n; ++i)
        ans.push_back(matrix[i][d]);
      for (int j = d; j >= a && ans.size() < m * n; --j)
        ans.push_back(matrix[c][j]);
      for (int i = c - 1; i >= a + 1 && ans.size() < m * n; --i)
        ans.push_back(matrix[i][b]);
      ++a, ++b, --c, --d;
    }
    return ans;
  }
};
