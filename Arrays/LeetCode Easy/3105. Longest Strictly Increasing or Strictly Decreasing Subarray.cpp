#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 : Brute Force
 * In this approach, we iterate over each index as a possible starting point and check for the longest increasing
 * and decreasing subarray separately. For each starting index, we traverse the remaining elements to find the
 * longest contiguous subarray that is either strictly increasing or strictly decreasing. We maintain a variable
 * --------------------
 * T.C : O(n^2) - We iterate over each index as a starting point (O(n)),and for each index, we traverse the remaining elements (O(n)), leading to an overall complexity of O(n^2).
 * --------------------
 * S.C : O(1)   - No extra space is used apart from a few integer variables.
 */
class Solution
{
public:
  int longestMonotonicSubarray(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the input array

    int result = 0; // Stores the maximum length of any monotonic subarray

    // Iterate over each index as a possible starting point
    for (int i = 0; i < n; i++)
    {
      int increasing = 1; // Length of the increasing subarray starting from index i
      int j = i + 1;      // Start checking from the next index

      // Check for the longest increasing subarray starting from index i
      while (j < n && nums[j] > nums[j - 1])
      {               // If the current element is greater than the previous one
        increasing++; // Increase the length of the increasing subarray
        j++;          // Move to the next element
      }

      int decreasing = 1; // Length of the decreasing subarray starting from index i
      j = i + 1;          // Reset j to check for decreasing sequence

      // Check for the longest decreasing subarray starting from index i
      while (j < n && nums[j] < nums[j - 1])
      {               // If the current element is smaller than the previous one
        decreasing++; // Increase the length of the decreasing subarray
        j++;          // Move to the next element
      }

      // Store the maximum length of increasing or decreasing subarray found so far
      result = max({result, increasing, decreasing});
    }

    return result; // Return the maximum length found
  }
};
