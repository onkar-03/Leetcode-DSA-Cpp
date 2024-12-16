#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// Time Complexity: O(n * k) - For each of the 'k' iterations, we traverse the 'n' elements of the array.
// Space Complexity: O(1) - We do not use any extra space except for variables.

class Solution
{
public:
  // Function to modify the input vector based on the given parameters
  // nums: input vector of integers
  // k: number of iterations
  // multiplier: value by which the minimum element is multiplied
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
  {
    int n = nums.size(); // Get the size of the input vector

    // Perform the operation 'k' times
    for (int j = 0; j < k; j++)
    {
      int idx = 0; // Variable to store the index of the smallest element

      // Find the index of the smallest element in the array
      for (int i = 0; i < n; i++)
      {
        if (nums[i] < nums[idx])
        {
          // If current element is smaller than the one at 'idx'
          // Update 'idx' to the current index
          idx = i;
        }
      }

      // Multiply the smallest element by the given multiplier
      nums[idx] *= multiplier;
    }

    // Return the modified vector after 'k' iterations
    return nums;
  }
};
