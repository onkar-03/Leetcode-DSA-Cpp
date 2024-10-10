#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using brute force) - Passes 95/101 test cases
// T.C : O(n^2)
// S.C : O(1)
class Solution
{
public:
  // A ramp is defined as a pair (i, j) where i < j and nums[i] <= nums[j].
  int maxWidthRamp(vector<int> &nums)
  {
    // Get the size of the input array
    int n = nums.size();

    // Initialize a variable to store the maximum ramp width found so far.
    int ramp = 0;

    // Use a nested loop to check every pair (i, j) such that i < j.
    // Outer loop iterates over all possible starting points of the ramp.
    for (int i = 0; i < n; ++i)
    {
      // Inner loop iterates over all possible ending points of the ramp that come after the current starting point i.
      for (int j = i + 1; j < n; ++j)
      {
        // Check if nums[i] is less than or equal to nums[j].
        // If the condition holds, we have found a valid ramp.
        if (nums[i] <= nums[j])
        {
          // Update the maximum ramp width found so far
          // by taking the difference between j and i.
          ramp = max(ramp, j - i);
        }
      }
    }
    // Return the maximum ramp width found.
    return ramp;
  }
};

// Approach-2 (Early Termination) - Passes 97/101 test cases
// T.C : O(n^2) in worst case
// S.C : O(1)
class Solution
{
public:
  int maxWidthRamp(vector<int> &nums)
  {
    // Get the size of the input array.
    int n = nums.size();

    // Initialize a variable to store the maximum ramp width found so far.
    int ramp = 0;

    // Use a nested loop to find the maximum ramp width.
    // Outer loop iterates over each index i from 0 to n - 1.
    for (int i = 0; i < n; i++)
    {
      // Inner loop starts from the last index (n-1) and moves backward.
      // It looks for the first index j such that j > i and nums[i] <= nums[j].
      for (int j = n - 1; j > i; j--)
      {
        // Step 4: If nums[i] is less than or equal to nums[j], a valid ramp is found.
        if (nums[i] <= nums[j])
        {
          // Update the maximum ramp width found so far.
          ramp = max(ramp, j - i);

          // Since we are moving backwards from the end, we break the loop once a valid ramp is found to maximize the difference between j and i.
          break;
        }
      }
    }

    // Return the maximum ramp width found.
    return ramp;
  }
};
