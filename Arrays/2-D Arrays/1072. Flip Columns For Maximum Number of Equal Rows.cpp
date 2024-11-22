#include <bits/stdc++.h>
using namespace std;

// Approach-2 (Using hashmap to store patterns)
// T.C : O(row * col)
// S.C : O(row*col)
class Solution
{
public:
  int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    unordered_map<string, int> mp; // O(m*n)

    for (auto &row : matrix)
    { // O(m)
      string rowKaNature = "";

      int firstVal = row[0];
      for (int col = 0; col < n; col++)
      { // O(n)
        rowKaNature += (row[col] == firstVal) ? "S" : "B";
      }

      mp[rowKaNature]++;
    }

    int maxRows = 0;
    for (auto &it : mp)
    {
      maxRows = max(maxRows, it.second);
    }

    return maxRows;
  }
};
