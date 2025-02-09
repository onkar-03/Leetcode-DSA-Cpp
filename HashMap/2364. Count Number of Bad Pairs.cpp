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
