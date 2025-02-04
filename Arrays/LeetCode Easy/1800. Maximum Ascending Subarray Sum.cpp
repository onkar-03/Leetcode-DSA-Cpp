#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force)
 * ---------------------------
 * - We iterate over each index as a starting point and check for the longest strictly increasing
 *   subarray starting from that index.
 * - We keep track of the sum of the current ascending subarray and update the maximum sum found.
 *
 * T.C : O(n^2)
 * - For each starting index, we iterate forward until the sequence stops increasing,
 *   leading to an O(n^2) worst-case complexity.
 *
 * S.C : O(1)
 * - No extra space is used apart from a few integer variables.
 * ---------------------------
 */
class Solution
{
public:
  int maxAscendingSum(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the input array

    int maxSum = 0; // Stores the maximum sum of an ascending subarray

    // Iterate over each index as a starting point
    for (int i = 0; i < n; i++)
    {
      int sum = nums[i]; // Initialize sum with the current element
      int j = i + 1;     // Start checking from the next index

      // Traverse while the subarray is strictly increasing
      while (j < n && nums[j] > nums[j - 1])
      {
        sum += nums[j]; // Add the current element to the sum
        j++;            // Move to the next element
      }

      // Update the maximum sum found so far
      maxSum = max(maxSum, sum);
    }

    return maxSum; // Return the maximum ascending subarray sum
  }
};
