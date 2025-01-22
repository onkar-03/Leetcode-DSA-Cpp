#include <bits/stdc++.h>
using namespace std;

// Approach-1: Brute Force
// Time Complexity: O(n^2) - Due to the nested loops iterating over all pairs of elements
// Space Complexity: O(1) - We are not using any extra space except the result
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int n = nums.size(); // Get the size of the input array 'nums'

    // Outer loop iterates over each element of the array
    for (int i = 0; i < n; i++)
    {
      // Inner loop starts from the next element to avoid checking the same pair again
      for (int j = i + 1; j < n; j++)
      {
        // Check if the sum of the current pair equals the target
        if (nums[i] + nums[j] == target)
        {
          // If found, return the indices of the two numbers
          return {i, j};
        }
      }
    }
    // If no such pair is found (not needed in this case as problem guarantees one solution)
  }
};
