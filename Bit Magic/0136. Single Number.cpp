#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force
 * - Iterate through the array and, for each element, count its occurrences in the array.
 * - Return the element that appears exactly once.
 * ----------------------------
 * T.C: O(n^2)
 * - For each element in the array (O(n)), a nested loop counts its occurrences (O(n)).
 * - Constants: Basic comparisons and increments are involved inside the nested loop.
 * ----------------------------
 * S.C: O(1)
 * - No extra data structures are used apart from variables.
 */
class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    // Get the size of the array
    int n = nums.size();

    // Check each element in the array
    for (int i = 0; i < n; i++)
    {
      int count = 0;

      // Count occurrences of nums[i] in the array
      for (int j = 0; j < n; j++)
      {
        if (nums[i] == nums[j])
        {
          count++;
        }
      }

      // If the count is exactly 1, return nums[i]
      if (count == 1)
      {
        return nums[i];
      }
    }

    // Return -1 if no single number is found (edge case)
    return -1;
  }
};

/*
 * Approach-2: Using Unordered Map
 * - Use an unordered_map to keep track of the frequency of each element in the array.
 * - The key in the map is the number (using `long long` type), and the value is the count of its occurrences.
 * - Iterate through the map and return the key with a count of 1 (the single number).
 *
 * T.C: O(n)
 * - The array is traversed once, and each insert/update operation in the unordered_map takes O(1) on average.
 * - Constants: Each insertion and lookup in the unordered_map is O(1) on average.
 *
 * S.C: O(n)
 * - The unordered_map stores each unique number from the array, so the space complexity is linear.
 * ----------------------------
 */

class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    // Create an unordered_map to store frequencies with long long keys
    unordered_map<long long, int> freqMap;

    // Traverse the array and update the frequency map
    for (int num : nums)
    {
      freqMap[num]++;
    }

    // Traverse the map to find the element with a frequency of 1
    for (auto &entry : freqMap)
    {
      if (entry.second == 1)
      {
        return entry.first;
      }
    }

    // Return -1 if no such element is found (edge case)
    return -1;
  }
};

/*
 * Approach-3: XOR Method to Find the Single Number
 * - Use the XOR operation to identify the number that appears only once in the array.
 * - XOR has the properties:
 *   1. x ^ x = 0 (a number XORed with itself is 0)
 *   2. x ^ 0 = x (a number XORed with 0 remains the same)
 * - XOR all elements in the array. All duplicate numbers will cancel out, leaving only the single number.
 * ----------------------------
 * T.C: O(n)
 * - The array is traversed once, so the time complexity is linear.
 * - Constants: Each iteration involves a single XOR operation, which is O(1).
 * ----------------------------
 * S.C: O(1)
 * - No extra space is used apart from the XOR accumulator variable.
 */
class Solution
{
public:
  int singleNumber(vector<int> &nums)
  {
    // Initialize a variable to store the XOR result
    int XOR = 0;

    // Get the size of the array
    int n = nums.size();

    // XOR all elements in the array
    for (int i = 0; i < n; i++)
    {
      XOR = XOR ^ nums[i]; // Accumulate the XOR result
    }

    // Return the single number
    return XOR;
  }
};
