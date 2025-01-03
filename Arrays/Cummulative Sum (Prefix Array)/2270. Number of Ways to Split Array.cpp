#include <bits/stdc++.h>
using namespace std;

// Approach-1: Using a Cumulative Sum Array (Prefix Sum Array)
// Time Complexity: O(N), as we iterate through the array twice - once to calculate the cumulative sum and once to check the splits.
// Space Complexity: O(N), as we use an additional array to store the cumulative sum.

class Solution
{
public:
  int waysToSplitArray(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the input array.

    // Step 1: Compute the cumulative sum array.
    vector<long long> cumSum(n);
    cumSum[0] = nums[0]; // Initialize the first element of the cumulative sum array.
    for (int i = 1; i < n; i++)
    {
      cumSum[i] = cumSum[i - 1] + nums[i]; // Each element is the sum of all previous elements and the current one.
    }

    int split = 0; // Initialize a counter to keep track of valid splits.

    // Step 2: Iterate through the array to determine valid splits.
    for (int i = 0; i < n - 1; i++)
    {                                                 // Only iterate up to the second last element.
      long long leftSum = cumSum[i];                  // Sum of elements in the left partition.
      long long rightSum = cumSum[n - 1] - cumSum[i]; // Sum of elements in the right partition.

      // Check if the left sum is greater than or equal to the right sum.
      if (leftSum >= rightSum)
      {
        split++; // Increment the counter for valid splits.
      }
    }

    return split; // Return the total count of valid splits.
  }
};
