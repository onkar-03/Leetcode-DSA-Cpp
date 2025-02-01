#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Simple iteration)
 * - Iterate through the array and check consecutive elements.
 * - If two adjacent elements have the same parity (both even or both odd), return false.
 * - If the loop completes without finding such a pair, return true.
 * --------------------
 * T.C: O(n)
 * - We traverse the array once, making it linear time complexity.
 * --------------------
 * S.C: O(1)
 * - No extra space is used apart from a few variables.
 * --------------------
 */

class Solution
{
public:
  bool isArraySpecial(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array

    // Iterate through the array and check consecutive elements
    for (int i = 0; i <= n - 2; i++)
    {
      // Check if both are even or both are odd
      if (nums[i] % 2 == nums[i + 1] % 2)
      {
        // Not a special array
        return false;
      }
    }

    // The array satisfies the special condition
    return true;
  }
};

/*
 * Approach-2 (Using Bit magic)
 * - We use bitwise AND operation to check the parity of the elements.
 * - The bitwise operation `(nums[i] & 1)` will give `1` if the number is odd and `0` if it's even.
 * - We compare the result for consecutive elements to ensure they have different parity.
 * - If any consecutive elements have the same parity, return false.
 * - If the loop completes without finding such a pair, return true.
 * --------------------
 * T.C: O(n)
 * - We traverse the array once, making it linear time complexity
 * --------------------
 * S.C: O(1)
 * - No extra space is used apart from a few variables
 */

class Solution
{
public:
  bool isArraySpecial(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array

    // Iterate through the array and check consecutive elements using bitwise operation
    for (int i = 0; i <= n - 2; i++)
    {
      // Check parity using bitwise AND
      if ((nums[i] & 1) == (nums[i + 1] & 1))
      {
        // Not a special array
        return false;
      }
    }

    // The array satisfies the special condition
    return true;
  }
};
