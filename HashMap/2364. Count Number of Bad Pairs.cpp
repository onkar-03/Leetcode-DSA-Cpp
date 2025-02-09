#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Brute Force) TLE
 * - We iterate over all pairs `(i, j)` where `i < j` and check if the condition `j - i != nums[j] - nums[i]` holds.
 * - If the condition is satisfied, we count it as a "bad pair."
 * - This approach checks all possible pairs, leading to a **quadratic time complexity**.
 * --------------------
 * T.C: O(n^2)
 * - We have a nested loop iterating over all pairs `(i, j)`, leading to **O(n^2)** complexity.
 * --------------------
 * S.C: O(1)
 * - We use only a few extra variables (`n` and `result`), so space complexity is **constant**.
 */

class Solution
{
public:
  long long countBadPairs(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array

    long long result = 0; // Initialize count of bad pairs

    // Iterate through all pairs (i, j) where i < j
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        // If the condition `j - i != nums[j] - nums[i]` holds, count it as a bad pair
        if (j - i != nums[j] - nums[i])
        {
          result++; // Increment bad pair count
        }
      }
    }

    return result; // Return the total number of bad pairs
  }
};

/*
 * Approach-2 (Using Hashmap)
 * - We transform `nums[i]` into `nums[i] - i` to simplify the condition check.
 * - We use a hashmap to store the frequency of transformed values encountered so far.
 * - For each index `j`, we calculate the number of good pairs using the hashmap and subtract from total pairs to get bad pairs.
 * --------------------
 * T.C: O(n)
 * - We traverse the array once to modify values (`O(n)`) and once to compute results using a hashmap (`O(n)`), leading to **O(n)** complexity.
 * --------------------
 * S.C: O(n)
 * - We use an unordered map to store frequency counts, which in the worst case holds `n` distinct values, leading to **O(n)** space.
 */

class Solution
{
public:
  long long countBadPairs(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array

    long long result = 0; // Initialize count of bad pairs

    // Transform array: nums[i] = nums[i] - i
    for (int i = 0; i < n; i++)
    {
      nums[i] = nums[i] - i;
    }

    unordered_map<int, int> mp; // Hashmap to track frequencies
    mp[nums[0]] = 1;            // Initialize with first element

    // Iterate through the array to count bad pairs
    for (int j = 1; j < n; j++)
    {
      int countOfNumsj = mp[nums[j]]; // Get frequency of nums[j] in hashmap

      int totalNumsBeforej = j; // Total elements before index `j`

      int badPairs = totalNumsBeforej - countOfNumsj; // Compute bad pairs

      result += badPairs; // Update result

      mp[nums[j]]++; // Update hashmap frequency
    }

    return result; // Return total bad pairs count
  }
};

/*
 * Approach-3 (Using Hashmap - Optimized)
 * - Instead of modifying the array separately, we directly compute the transformed value `diff = nums[i] - i`.
 * - We maintain a hashmap to store the frequency of each `diff` encountered so far.
 * - At each index `i`, we calculate the total pairs formed (`i` pairs before it) and subtract the good pairs to get bad pairs.
 * --------------------
 * T.C: O(n)
 * - We traverse the array once and use a hashmap for constant-time lookups, leading to **O(n)** complexity.
 * --------------------
 * S.C: O(n)
 * - The unordered map stores at most `n` elements, leading to **O(n)** space.
 */

class Solution
{
public:
  long long countBadPairs(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array

    long long result = 0;       // Initialize count of bad pairs
    unordered_map<int, int> mp; // Hashmap to track frequencies of (nums[i] - i)

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
      int diff = nums[i] - i; // Compute transformed value

      int totalPairsTillIndex = i; // Total pairs before current index
      int goodPairs = mp[diff];    // Count of good pairs from hashmap

      result += (totalPairsTillIndex - goodPairs); // Compute and add bad pairs

      mp[diff]++; // Update hashmap frequency
    }

    return result; // Return total bad pairs count
  }
};
