#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> construct2DArray(vector<int> &original, int m, int n)
  {
    // Check if the size of the original array is valid for conversion to a 2D array
    if (original.size() != m * n)
      return {}; // Return an empty 2D array if sizes don't match

    vector<vector<int>> res; // Initialize result 2D vector

    // Iterate over each row
    for (int i = 0; i < m; i++)
    {
      int start = n * i;   // Starting index of the current row in the original array
      int end = start + n; // End index (exclusive) for the current row

      // Create a row from the original array and push it to the result
      res.push_back(vector<int>(original.begin() + start, original.begin() + end));
    }

    return res; // Return the constructed 2D array
  }
};

int main()
{
  Solution solution;

  vector<int> arr = {1, 2, 3, 4};
  int m = 2;
  int n = 2;

  vector<vector<int>> ans = solution.construct2DArray(arr, m, n);

  for (auto it : ans)
  {
    for (auto jt : it)
    {
      cout << jt << " ";
    }
    cout << endl; // Print each row of the result 2D array
  }

  return 0;
}