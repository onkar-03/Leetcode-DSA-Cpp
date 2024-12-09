#include <bits/stdc++.h>
using namespace std;

// Approach-1: Using cumulative sum to efficiently handle range queries
// Time Complexity: O(n + m), where n is the size of the array `nums` and m is the number of queries.
// Space Complexity: O(n), for storing the cumulative sum array.

class Solution
{
public:
  vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
  {
    int n = nums.size();
    int m = queries.size();

    // Step 1: Initialize the cumulative sum array.
    // cumSum[i] stores the total count of "violating indices" from the start of the array up to index `i`.
    // A "violating index" occurs when two consecutive elements have the same parity (both even or both odd).
    vector<int> cumSum(n, 0);

    // Step 2: Build the cumulative sum array.
    for (int i = 1; i < n; i++)
    {
      if (nums[i] % 2 == nums[i - 1] % 2)
      {                                // Check if consecutive elements have the same parity.
        cumSum[i] = cumSum[i - 1] + 1; // Increment the count of violating indices.
      }
      else
      {
        cumSum[i] = cumSum[i - 1]; // No violation; carry forward the previous count.
      }
    }

    // Step 3: Process each query to determine if the subarray is "special".
    // A subarray is "special" if it contains no violating indices.
    vector<bool> result(m, false); // Initialize result array to store boolean results.
    int i = 0;                     // Index to iterate through the queries.

    for (vector<int> &query : queries)
    {
      int start = query[0];
      int end = query[1];

      // Use the cumulative sum array to check if there are any violations in the range [start, end].
      if (cumSum[end] - cumSum[start] == 0)
      {
        result[i] = true; // Subarray is "special" (no violations found).
      }
      i++;
    }

    return result; // Return the results for all queries.
  }
};
