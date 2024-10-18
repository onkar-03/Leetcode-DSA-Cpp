#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using simple recursion to find subsets)
// T.C : O(2^n)
// S.C : O(1)
class Solution
{
public:
  // Recursive function to count subsets with maximum OR value
  // idx: Current index in the nums array
  // currOr: The OR value of the current subset being considered
  // nums: Input array of numbers
  // maxOr: The maximum OR value that we want to achieve
  // Returns the number of subsets with OR equal to maxOr
  int countSubsets(int idx, int currOr, vector<int> &nums, int maxOr)
  {
    // Base case: If we have considered all elements (idx == nums.size())
    if (idx == nums.size())
    {
      // If the OR of the current subset equals maxOr, count this subset
      if (currOr == maxOr)
        return 1; // Found one valid subset
      return 0;   // This subset is not valid (doesn't match maxOr)
    }

    // Recursive case 1: Include nums[idx] in the subset, update the OR value
    int takeCount = countSubsets(idx + 1, currOr | nums[idx], nums, maxOr);

    // Recursive case 2: Exclude nums[idx] from the subset, keeping the OR value unchanged
    int notTakeCount = countSubsets(idx + 1, currOr, nums, maxOr);

    // Total subsets count: Add the counts from both recursive cases
    return takeCount + notTakeCount;
  }

  // Main function to calculate the count of subsets with the maximum OR value
  int countMaxOrSubsets(vector<int> &nums)
  {
    int maxOr = 0; // This will store the maximum OR value of the entire array

    // Calculate the maximum OR value that can be achieved using all elements
    for (int &num : nums)
    {
      maxOr |= num; // OR each number with maxOr to find the maximum possible OR
    }

    int currOr = 0; // Start with an empty subset (OR value = 0)
    // Call the recursive function to count subsets with OR equal to maxOr
    return countSubsets(0, currOr, nums, maxOr);
  }
};

// Approach-2 (Memoizing to store subproblems result)
// T.C : O(n*maxOr)
// S.C : O(1)
class Solution
{
public:
  // Recursive function to count subsets with memoization
  // idx: Current index in the nums array
  // currOr: The OR value of the current subset being considered
  // nums: Input array of numbers
  // maxOr: The maximum OR value that we want to achieve
  // t: Memoization table to store results of subproblems
  // Returns the number of subsets with OR equal to maxOr
  int countSubsets(int idx, int currOr, vector<int> &nums, int maxOr, vector<vector<int>> &t)
  {
    // Base case: If we have considered all elements (idx == nums.size())
    if (idx == nums.size())
    {
      // If the OR of the current subset equals maxOr, count this subset
      if (currOr == maxOr)
        return t[idx][currOr] = 1; // Found one valid subset
      return t[idx][currOr] = 0;   // This subset is not valid (doesn't match maxOr)
    }

    // If the result for this subproblem is already computed, return it from memoization table
    if (t[idx][currOr] != -1)
    {
      return t[idx][currOr];
    }

    // Recursive case 1: Include nums[idx] in the subset, update the OR value
    int takeCount = countSubsets(idx + 1, currOr | nums[idx], nums, maxOr, t);

    // Recursive case 2: Exclude nums[idx] from the subset, keeping the OR value unchanged
    int notTakeCount = countSubsets(idx + 1, currOr, nums, maxOr, t);

    // Store the result for this subproblem in the memoization table and return the total count
    return t[idx][currOr] = takeCount + notTakeCount;
  }

  // Main function to calculate the count of subsets with the maximum OR value
  int countMaxOrSubsets(vector<int> &nums)
  {
    int maxOr = 0; // This will store the maximum OR value of the entire array

    // Calculate the maximum OR value that can be achieved using all elements
    for (int &num : nums)
    {
      maxOr |= num; // OR each number with maxOr to find the maximum possible OR
    }

    int n = nums.size(); // Get the number of elements in the array

    // Create a memoization table `t` with dimensions (n+1) x (maxOr+1) initialized to -1
    // t[i][j] will store the number of subsets that can be formed with elements from index `i`
    // and OR value `j`.
    vector<vector<int>> t(n + 1, vector<int>(maxOr + 1, -1));

    int currOr = 0; // Start with an empty subset (OR value = 0)
    // Call the recursive function to count subsets with OR equal to maxOr
    return countSubsets(0, currOr, nums, maxOr, t);
  }
};