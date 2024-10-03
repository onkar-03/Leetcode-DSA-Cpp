#include <bits/stdc++.h>
using namespace std;

// Approach: Using prefix sum modulo and storing results in a hashmap
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution
{
public:
  int minSubarray(vector<int> &nums, int p)
  {
    // Step 1: Calculate the sum of all elements and take its modulo with `p`
    int Sum = 0;

    // Explanation:
    // We use the property of modular arithmetic:
    // (a + b) % p = (a % p + b % p) % p
    // Here, we iterate over all numbers and compute the total sum % p.
    for (int &num : nums)
    {
      Sum = (Sum + num) % p;
    }

    // Step 2: `target` is the remainder we need to remove to make the sum divisible by `p`
    // If `Sum % p == 0`, the entire array's sum is already divisible by `p`, so no need to remove any subArray
    // int target = Sum % p; OR int target = Sum; same as we already calculated the target only from Sum = (Sum + num) % p;
    int target = Sum;

    // If the total sum is already divisible by `p`, return 0 since no subArray needs to be removed
    if (target == 0)
    {
      return 0;
    }

    // Step 3: Use a hashmap to store the prefix sums and their indices
    // We store the modulo result of prefix sums to detect which subArray sum can be removed, also to avoid out of bounds for larger numbers
    // mp[rem] stores the last occurrence of a prefix sum with remainder `rem % p`
    unordered_map<int, int> mp;

    // Step 4: Initialize the prefix sum for the first element as `0`, because prefix sum at index -1 is considered zero
    mp[0] = -1;

    // `currSum` tracks the running prefix sum as we process the array
    int currSum = 0;

    // Size of the Array
    int n = nums.size();

    // `result` keeps track of the length of the minimum subArray to remove
    int result = n; // Initialize result to `n` (worst case, removing the whole array)

    // Step 5: Iterate through the array to find the subArray that, when removed, makes the sum divisible by `p`
    for (int j = 0; j < n; j++)
    {
      // Update the prefix sum modulo `p` at each step (using modulo to avoid overflow)
      // Store the current remainder in the map (this represents the prefix sum mod `p`)
      currSum = (currSum + nums[j]) % p;

      // Calculate the required remainder (`remain`) that would cancel out `target`
      // `remain` is the remainder of a subArray that can be removed to balance the sum modulo `p`
      int remain = (currSum - target + p) % p;

      // Step 6: If we have seen this remainder before, it means we found a valid subArray
      // If the remainder was seen before (in the hashmap), then the subArray between that index and `j` has the sum we need
      if (mp.find(remain) != mp.end())
      {
        // Update result with the minimum length of the subArray that satisfies the condition
        result = min(result, j - mp[remain]);
      }

      // Update the map with the current remainder for the next iteration
      mp[currSum] = j;
    }

    // If no valid subArray was found, return -1. Otherwise, return the length of the shortest subArray found
    return result == n ? -1 : result;
  }
};
