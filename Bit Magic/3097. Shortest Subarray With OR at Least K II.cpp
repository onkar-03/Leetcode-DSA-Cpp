#include <bits/stdc++.h>
using namespace std;

// Approach: Sliding Window with Bitwise Operations
// Goal: Find the minimum length of a subarray with an OR sum greater than or equal to 'k'
// Time Complexity: O(n), where n is the size of the input array
// Space Complexity: O(1), ignoring the space required for the 32-bit vector
class Solution
{
public:
  void update(int number, vector<int> &vec, int val)
  {
    for (int i = 0; i < 32; i++)
    { // Loop through all 32 bits
      if ((number >> i) & 1)
      {
        // Check if the i-th bit in 'number' is set
        // Add 'val' (1 or -1) to the bit count at the i-th position
        vec[i] += val;
      }
    }
  }

  int getDecimalFromBinary(vector<int> &vec)
  {
    int num = 0;

    for (int i = 0; i < 32; i++)
    { // Loop through all 32 bits
      if (vec[i] > 0)
      { // If there are any set bits at the i-th position
        // Set the i-th bit in 'num' to 1
        num |= (1 << i);
      }
    }

    return num;
  }

  int minimumSubarrayLength(vector<int> &nums, int k)
  {
    int n = nums.size();  // Length of the input array
    int result = INT_MAX; // Initialize result to maximum value
    int i = 0;            // Left boundary of the sliding window
    int j = 0;            // Right boundary of the sliding window

    // Vector to store count of set bits for each of the 32 positions
    vector<int> vec(32, 0);

    // Sliding window approach: Traverse the array with j as the expanding boundary
    while (j < n)
    { // Iterate until the right boundary reaches the end of the array
      // Add nums[j] to the current window and update set bits in 'vec'
      update(nums[j], vec, 1);

      // Shrink the window from the left if the OR sum >= k
      while (i <= j && getDecimalFromBinary(vec) >= k)
      {
        result = min(result, j - i + 1); // Update result if we found a smaller subarray
        update(nums[i], vec, -1);        // Remove nums[i] from the window and adjust 'vec' accordingly

        // Move the left boundary of the window to the right
        i++;
      }

      // Expand the window to the right by incrementing j
      j++;
    }

    // Return the minimum subarray length if found, else return -1 if no valid subarray was found
    return result == INT_MAX ? -1 : result;
  }
};
