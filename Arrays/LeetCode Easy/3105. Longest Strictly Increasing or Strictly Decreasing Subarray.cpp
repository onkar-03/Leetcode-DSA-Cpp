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
      // Length of the increasing subarray starting from index i
      int increasing = 1;

      // Start checking from the next index
      int j = i + 1;

      // Check for the longest increasing subarray starting from index i
      // If the current element is greater than the previous one
      while (j < n && nums[j] > nums[j - 1])
      {
        increasing++; // Increase the length of the increasing subarray
        j++;          // Move to the next element
      }

      // Length of the decreasing subarray starting from index i
      int decreasing = 1;

      // Reset j to check for decreasing sequence
      j = i + 1;

      // Check for the longest decreasing subarray starting from index i
      // If the current element is smaller than the previous one
      while (j < n && nums[j] < nums[j - 1])
      {
        // Increase the length of the decreasing subarray
        decreasing++;
        // Move to the next element
        j++;
      }

      // Store the maximum length of increasing or decreasing subarray found so far
      result = max({result, increasing, decreasing});
    }

    return result; // Return the maximum length found
  }
};

/*
 * Approach-2 : Using Two Pointers (Increment and Decrement Tracking)
 * - The approach maintains two variables, `inc` and `dec`, to track the length of the increasing and decreasing subarrays, respectively.
 * - We traverse the array and compare each element with its previous one. If the current element is larger, we increment `inc` and reset `dec`. If it's smaller, we increment `dec` and reset `inc`. If they are equal, both `inc` and `dec` are reset.
 * - At each step, we update `maxi` to store the length of the longest monotonic subarray found so far.
 * - If no valid subarray is found, we return 1 since the minimum subarray length is 1 (the element itself).
 * ---------------------------
 * T.C : O(n) - We iterate through the array once to track the lengths of increasing and decreasing subarrays
 * ---------------------------
 * S.C : O(1) - Constant space used for the variables `inc`, `dec`, and `maxi`.
 */
class Solution
{
public:
  int longestMonotonicSubarray(vector<int> &nums)
  {
    int n = nums.size(); // Get the length of the input array

    int inc = 1;        // Track the length of the increasing subarray
    int dec = 1;        // Track the length of the decreasing subarray
    int maxi = INT_MIN; // Initialize maxi to the smallest integer value

    // Traverse the array starting from the second element
    for (int i = 1; i < n; i++)
    {

      // If the current element is greater than the previous, it's an increasing subarray
      if (nums[i] > nums[i - 1])
      {
        inc++;                 // Increase the length of the increasing subarray
        dec = 1;               // Reset the length of the decreasing subarray
        maxi = max(maxi, inc); // Update maxi with the maximum length found so far
      }
      // If the current element is smaller than the previous, it's a decreasing subarray
      else if (nums[i] < nums[i - 1])
      {
        dec++;                 // Increase the length of the decreasing subarray
        inc = 1;               // Reset the length of the increasing subarray
        maxi = max(maxi, dec); // Update maxi with the maximum length found so far
      }
      // If the current element is equal to the previous, reset both inc and dec
      else
      {
        inc = 1;
        dec = 1;
      }
    }

    // If no valid subarray was found, return 1 (the smallest possible subarray length)
    return maxi == INT_MIN ? 1 : maxi;
  }
};