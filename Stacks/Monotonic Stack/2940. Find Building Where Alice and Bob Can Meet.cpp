#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
  using int2 = pair<int, int>; // Alias for a pair of integers

  vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
  {
    int n = heights.size();  // Number of buildings
    int qz = queries.size(); // Number of queries
    vector<int> ans(qz, -1); // Initialize the answers with -1
    vector<int2> idx;        // Store deferred queries (y, query index)

    // Preprocess queries
    for (int i = 0; i < qz; i++)
    {
      int &x = queries[i][0]; // Start building
      int &y = queries[i][1]; // End building
      if (x > y)
      { // Ensure x <= y for consistency
        swap(x, y);
      }
      if (x == y || heights[x] < heights[y])
      {
        ans[i] = y; // Directly answer if building y is taller
      }
      else
      {
        idx.emplace_back(y, i); // Defer processing for these queries
      }
    }

    // Sort the deferred queries by `y` in descending order
    sort(idx.begin(), idx.end(), greater<>());

    vector<int2> stack; // Monotonic stack for tracking leftmost taller buildings
    int j = n - 1;      // Start processing from the last building

    // Process deferred queries
    for (const auto &p : idx)
    {
      int y = p.first;  // The end building of the query
      int i = p.second; // The query index
      int x = queries[i][0];

      // Update the monotonic stack for all buildings beyond `y`
      for (; j > y; j--)
      {
        // Maintain decreasing order of heights in the stack
        while (!stack.empty() && heights[stack.back().second] < heights[j])
        {
          stack.pop_back();
        }
        stack.emplace_back(heights[j], j); // Add current building to the stack
      }

      // Use binary search to find the leftmost taller building for `x`
      auto it = upper_bound(stack.rbegin(), stack.rend(), make_pair(heights[x], n));
      ans[i] = (it == stack.rend()) ? -1 : it->second; // Update the answer
    }

    return ans; // Return the final answers
  }
};

// Fast input/output for competitive programming
auto init = []()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 'c';
}();
