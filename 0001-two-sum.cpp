#include <bits/stdc++.h>
using namespace std;

/*
--- Brute Force Solution to Two Sum Problem:

Given an array of integers nums and an integer target, the task is to find the indices of the two numbers such that they add up to the target value. This problem is a classic example of using a brute force approach to solve the two-sum problem.ys.

The `twoSum` function employs two nested loops to examine all possible pairs of elements. It checks if
the sum of any two distinct elements equals the target. If such a pair is found, the function returns their indices.

-- Time Complexity: O(n^2) - Due to the nested loops, where n is the number of elements in the array.
-- Space Complexity: O(1) - No extra space is used that scales with the input size.

This approach ensures that if a solution exists, it will be found, but it may not be optimal for very large arrays.
*/

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    // Iterate over each element of the vector nums
    for (int i = 0; i < nums.size(); i++)
    {
      // For each `i`, iterate over subsequent elements with an index `j`
      for (int j = i + 1; j < nums.size(); j++)
      {
        // Check if the sum of nums[i] and nums[j] equals the target
        if (nums[i] + nums[j] == target)
          // Return the indices of the two numbers that add up to the target
          return {i, j};
      }
    }
    // Return an empty vector if no valid pair is found
    return {};
  }
};

/*
--- HashMap Method

The HashMap method provides an optimized solution for the two-sum problem with a time complexity of O(n)
and a space complexity of O(n). This approach uses an unordered_map to store the indices of the elements
as we iterate through the array. By leveraging the properties of the unordered_map, we can efficiently check
if the complement of the current element (i.e., target - nums[i]) has been previously encountered.

Time Complexity: O(n) - Each element is processed once, and hash map operations (insert and find) are O(1) on average.
Space Complexity: O(n) - The hash map stores up to n elements, where n is the number of elements in the array.
*/

// --- Hash Map Solution
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    int n = nums.size();
    unordered_map<int, int> mp; // Hash map to store value -> index

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
      // Calculate the complement value needed to reach the target
      int complement = target - nums[i];

      // Check if the complement is already in the hash map
      if (mp.find(complement) != mp.end())
      {
        // If found, return the indices of the complement and the current element
        return {mp[complement], i};
      }

      // Store the index of the current element in the hash map
      mp.insert({nums[i], i});
    }
    // Return an empty vector if no valid pair is found
    return {};
  }
};

int main()
{
  Solution solution;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  // Get the result from the twoSum function
  vector<int> result = solution.twoSum(nums, target);

  // Output the result
  cout << "Indices of the numbers that add up to " << target << " are: ";
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
