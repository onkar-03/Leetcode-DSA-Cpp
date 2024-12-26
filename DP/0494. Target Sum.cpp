#include <bits/stdc++.h>
using namespace std;

// Approach-1: Normal Recursion with Memoization using unordered_map
// Time Complexity: O(n * totalSum)
// Space Complexity: O(n * totalSum)
class Solution
{
public:
  // Helper function to solve the problem recursively
  int solve(vector<int> &nums, int &target, int i, int sum, unordered_map<string, int> &memo)
  {
    // Base case: If we have reached the end of the array
    if (i == nums.size())
    {
      // Check if the current sum equals the target
      return sum == target ? 1 : 0;
    }

    // Create a unique key for the current state (index and sum)
    string key = to_string(i) + "," + to_string(sum);

    // If the result for this state is already computed, return it
    if (memo.find(key) != memo.end())
    {
      return memo[key];
    }

    // Recursive calls:
    // 1. Add the current element to the sum
    // 2. Subtract the current element from the sum
    int plus = solve(nums, target, i + 1, sum + nums[i], memo);
    int minus = solve(nums, target, i + 1, sum - nums[i], memo);

    // Store the total number of ways in the memo for this state
    memo[key] = plus + minus;

    return memo[key];
  }

  // Main function to find the number of ways to achieve the target sum
  int findTargetSumWays(vector<int> &nums, int target)
  {
    // Memoization table to store results of previously computed states
    unordered_map<string, int> memo;
    // Start solving from index 0 with an initial sum of 0
    return solve(nums, target, 0, 0, memo);
  }
};
