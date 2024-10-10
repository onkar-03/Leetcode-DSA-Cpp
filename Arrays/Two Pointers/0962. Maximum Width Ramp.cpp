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

// Approach-3 : Two Pointer (Making use of hint from Approach-2, storing max to the right) - ACCEPTED
// T.C : O(n)
// S.C : O(n)
class Solution
{
public:
  int maxWidthRamp(vector<int> &nums)
  {
    // Get the size of the input array.
    int n = nums.size();

    // Initialize a variable to store the maximum ramp width found so far.
    int ramp = 0;

    // Create a vector to store the maximum element from the right side of the array for each index.
    // This helps us check for the largest possible nums[j] for a given index i efficiently.
    vector<int> maxToRight(n, 0);

    // Set the last element of the maxToRight array to be the last element of nums.
    // This is because there are no elements to the right of the last element.
    maxToRight[n - 1] = nums[n - 1];

    // Traverse the array in reverse to fill in the maxToRight array.
    // Each element in maxToRight[i] will contain the maximum value from index i to n-2 in nums.
    for (int i = n - 2; i >= 0; i--)
    {
      // For each i, store the maximum of the current nums[i] and the maximum value to its right.
      maxToRight[i] = max(maxToRight[i + 1], nums[i]);
    }

    // Initialize two pointers, i and j.
    // i is used to check the starting point of the ramp, and j is used to check the ending point.
    int i = 0;
    int j = 0;

    // Loop while j is within the bounds of the array.
    while (j < n)
    {
      // While nums[i] is greater than the maximum value in the remaining portion of the array, increment i to find the next valid starting point for the ramp.
      while (i < j && nums[i] > maxToRight[j])
      {
        i++;
      }

      // If nums[i] <= maxToRight[j], calculate the width of the ramp (j - i) and update the maximum ramp width.
      ramp = max(ramp, j - i);

      // Increment j to continue checking for wider ramps.
      j++;
    }

    // Return the maximum ramp width found.
    return ramp;
  }
};
