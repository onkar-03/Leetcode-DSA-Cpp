#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minimumMountainRemovals(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the input array

    // Initialize two vectors, LIS and LDS, to store lengths of
    // Longest Increasing Subsequence (LIS) and Longest Decreasing Subsequence (LDS) at each index
    vector<int> LIS(n, 1);
    vector<int> LDS(n, 1);

    // Calculate LIS for each element from left to right
    for (int i = 0; i < n; i++)
    {
      for (int j = i - 1; j >= 0; j--)
      {
        // If the current element nums[i] is greater than nums[j],
        // update LIS[i] as the maximum of LIS[i] and LIS[j] + 1
        if (nums[i] > nums[j])
        {
          LIS[i] = max(LIS[i], LIS[j] + 1);
        }
      }
    }

    // Calculate LDS for each element from right to left
    for (int i = n - 1; i >= 0; i--)
    {
      for (int j = i + 1; j < n; j++)
      {
        // If the current element nums[i] is greater than nums[j],
        // update LDS[i] as the maximum of LDS[i] and LDS[j] + 1
        if (nums[i] > nums[j])
        {
          LDS[i] = max(LDS[i], LDS[j] + 1);
        }
      }
    }

    // Initialize minRemovals to store the minimum removals needed to form a mountain array
    int minRemovals = INT_MAX;

    // Traverse through each index to calculate the minimum removals needed
    for (int i = 0; i < n; i++)
    {
      // Check if the index can form a peak (both LIS[i] and LDS[i] > 1)
      if (LIS[i] > 1 && LDS[i] > 1)
      {
        // Update minRemovals by calculating the number of elements to remove
        minRemovals = min(minRemovals, n - LIS[i] - LDS[i] + 1);
      }
    }

    // Return the minimum removals needed
    return minRemovals;
  }
};
