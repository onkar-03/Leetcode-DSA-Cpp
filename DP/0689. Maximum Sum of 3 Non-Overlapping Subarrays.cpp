#include <bits/stdc++.h>
using namespace std;

// Approach (Recursion + Memoization + sliding window)
// T.C : ~O(n) (Explained in the video above)
// S.C : ~O(n)
class Solution
{
private:
  // Memoization table for storing intermediate results
  int t[20001][4];

  int helper(vector<int> &sums, int k, int idx, int rem)
  {
    // Base case: if no more subarrays are needed
    if (rem == 0)
      return 0;

    // Base case: if index goes out of bounds
    if (idx >= sums.size())
    {
      return INT_MIN; // Return a very small value since this path is invalid
    }

    // Check if result is already computed
    if (t[idx][rem] != -1)
    {
      return t[idx][rem];
    }

    // Option 1: Take the current subarray and move to the next valid position
    int take = sums[idx] + helper(sums, k, idx + k, rem - 1);

    // Option 2: Skip the current subarray and move to the next position
    int not_take = helper(sums, k, idx + 1, rem);

    // Store the result in the memoization table
    t[idx][rem] = max(take, not_take);

    return t[idx][rem];
  }

  void solve(vector<int> &sums, int k, int idx, int rem, vector<int> &indices)
  {
    // Base case: no more subarrays to select
    if (rem == 0)
      return;

    // Base case: if index goes out of bounds
    if (idx >= sums.size())
      return;

    // Calculate the two options
    int take = sums[idx] + helper(sums, k, idx + k, rem - 1);
    int not_take = helper(sums, k, idx + 1, rem);

    // Choose the option with the higher sum
    if (take >= not_take)
    {
      indices.push_back(idx);                    // Select the current subarray
      solve(sums, k, idx + k, rem - 1, indices); // Recur for the next subarray
    }
    else
    {
      solve(sums, k, idx + 1, rem, indices); // Skip the current subarray
    }
  }

public:
  vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
  {
    // Initialize the memoization array with -1
    memset(t, -1, sizeof(t));

    // Calculate the number of possible subarray starting positions
    int n = nums.size() - k + 1;

    // Array to store the sum of all subarrays of size k
    vector<int> sums;
    int windowSum = 0; // Sum of the current sliding window
    int i = 0, j = 0;

    // Sliding window to calculate all subarray sums of size k
    while (j < nums.size())
    {
      windowSum += nums[j];

      // Check if the window size is equal to k
      if (j - i + 1 == k)
      {
        sums.push_back(windowSum); // Store the sum of the current window
        windowSum -= nums[i];      // Slide the window forward
        i++;
      }
      j++;
    }

    // Vector to store the indices of the selected subarrays
    vector<int> indices;

    // Reconstruct the path to find the indices of the maximum sum subarrays
    solve(sums, k, 0, 3, indices);

    return indices; // Return the indices of the selected subarrays
  }
};
