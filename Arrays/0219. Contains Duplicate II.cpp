#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force (Nested Loop) TLE
 * --------------------------------------
 * Time Complexity (T.C): O(n^2)
 * - The outer loop iterates 'n' times (for each element in the array).
 * - The inner loop iterates (n - 1) times for each outer loop iteration, resulting in O(n^2) comparisons.
 * - This leads to a quadratic time complexity of O(n^2).
 * --------------------------------------
 * Space Complexity (S.C): O(1)
 * - No extra space is used except for loop counters and the result.
 * - Thus, space complexity is constant: O(1).
 */

class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    // Traverse through each element in the array
    for (int i = 0; i < nums.size(); i++)
    {
      // Compare the current element with every subsequent element in the array
      for (int j = i + 1; j < nums.size(); j++)
      {
        // If a duplicate is found and the absolute difference in indices is <= k
        if (nums[i] == nums[j] && abs(j - i) <= k)
        {
          return true; // Return true if condition is satisfied
        }
      }
    }
    // If no duplicates are found, return false
    return false;
  }
};

/*
 * Approach-2: Using Hash Map (unordered_map)
 * -----------------------------------------
 * Time Complexity: O(n)
 * - We iterate through the array once, and each map operation (find and insert)
 * takes O(1) on average.
 * - Therefore, the total time complexity is O(n), where n is the size of the
 * input array.
 *
 * Space Complexity: O(n)
 * - The unordered_map stores up to n elements in the worst case, where n is the
 * size of the input array.
 * - Therefore, the space complexity is O(n).
 */

class Solution
{
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k)
  {
    // Create an unordered_map to store the element and its index
    unordered_map<int, int> mp;

    // Traverse through the array
    for (int i = 0; i < nums.size(); i++)
    {

      // Check if the current element exists in the map and if the absolute difference between indices is <= k
      if (mp.find(nums[i]) != mp.end())
      {
        if (abs(mp[nums[i]] - i) <= k)
          // Return true if found
          return true;
      }

      else
        // If not found, store the element and its index in the map
        mp[nums[i]] = i;
    }

    // If no duplicates found within the specified range, return false
    return false;
  }
};
