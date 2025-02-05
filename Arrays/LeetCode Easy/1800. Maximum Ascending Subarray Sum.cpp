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

/*
 * Approach-2 : Using Dynamic Programming Single Iteration
 * - We iterate through the array and track the sum of the current ascending subarray.
 * - If the current element is greater than the previous one, we add it to the current subarray sum.
 * - If the current element is smaller or equal, we compare the current subarray sum to the maximum sum found so far (`maxSum`) and reset the current sum to the new subarray starting from the current element.
 * - Finally, we return the maximum sum encountered during the iteration.
 * ---------------------------
 * T.C : O(n) - We iterate through the array once, comparing each element with the previous one.
 * ---------------------------
 * S.C : O(1) - We use a constant amount of space for the variables `maxSum` and `currSum`.
 */
class Solution
{
public:
  int maxAscendingSum(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array
    int sum = 0;

    // If there's only one element, return that element
    if (n == 1)
    {
      return nums[0];
    }

    int maxSum = 0;        // Variable to track the maximum sum of ascending subarrays
    int currSum = nums[0]; // Current sum starts with the first element

    // Traverse through the array from the second element
    for (int i = 1; i < n; i++)
    {
      // If the current element is greater than the previous, add it to the current subarray sum
      if (nums[i] > nums[i - 1])
      {
        currSum += nums[i];
      }
      // If not, update the maximum sum and reset the current sum
      else
      {
        maxSum = max(maxSum, currSum);
        currSum = nums[i];
      }
    }

    // Return the maximum sum between the last calculated sum and the current sum
    return max(maxSum, currSum);
  }
};