#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Brute Force
 * - Iterate through all possible numbers from 0 to n (inclusive).
 * - For each number, check if it exists in the array by iterating through the array.
 * - If a number is not found, return it as the missing number.
 * - If no missing number is found, return -1 (though this case won't occur for valid inputs).
 * ----------------------------
 * T.C: O(n^2)
 * - The outer loop runs from 0 to n (n+1 iterations).
 * - For each iteration of the outer loop, we perform an inner loop to check for the existence of the number, which takes O(n) time.
 * ----------------------------
 * S.C: O(1)
 * - No extra space is used apart from a few variables.
 */
class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    // Get the size of the array
    int n = nums.size();

    // Iterate through all numbers from 0 to n
    for (int i = 0; i <= n; i++)
    {
      int flag = 0; // Flag to check if the number exists in the array

      // Iterate through the array to check if the current number exists
      for (int j = 0; j < n; j++)
      {
        if (nums[j] == i)
        { // If the number exists, set flag to 1 and break
          flag = 1;
          break;
        }
      }

      // If the flag is still 0, return the current number as missing
      if (flag == 0)
      {
        return i;
      }
    }

    // Return -1 if no missing number is found (won't happen for valid inputs)
    return -1;
  }
};

/*
 * Approach: Sum Difference Method (Optimal Solution)
 * - Calculate the sum of numbers from 0 to n using the formula `sum = n * (n + 1) / 2` or by iterating from 0 to n.
 * - Calculate the sum of all elements in the given array.
 * - The missing number is the difference between the calculated sum (0 to n) and the sum of elements in the array.
 * ----------------------------
 * T.C: 2*O(n)
 * - Calculating the sum from 0 to n takes O(n) time (in the given implementation).
 * - Calculating the sum of array elements also takes O(n) time.
 * - Therefore, the overall time complexity is O(n).
 * ----------------------------
 * S.C: O(1)
 * - No extra space is used apart from a few variables.
 */
class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    // Get the size of the array
    int n = nums.size();

    // Calculate the sum of numbers from 0 to n
    int origSum = 0;
    for (int i = 0; i <= n; i++)
    {
      origSum += i;
    }

    // Calculate the sum of elements in the array
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += nums[i];
    }

    // Return the difference as the missing number
    return origSum - sum;
  }
};

/*
 * Approach-3: XOR Method (Optimal Solution)
 * - XOR all numbers from 0 to n (inclusive) to compute `XOR1`.
 * - XOR all elements in the given array to compute `XOR2`.
 * - The missing number is determined by taking the XOR of `XOR1` and `XOR2`, as numbers appearing in both sequences will cancel out, leaving the missing number.
 * ----------------------------
 * T.C: O(n + n) = O(2n) = O(n)
 * - The first loop to compute `XOR1` runs O(n+1) times, which is O(n).
 * - The second loop to compute `XOR2` runs O(n) times.
 * - Constants: Both loops are linear with simple XOR operations.
 * ----------------------------
 * S.C: O(1)
 * - Only a constant amount of extra space is used for variables (`XOR1` and `XOR2`).
 */
class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    // Get the size of the array
    int n = nums.size();

    // XOR all numbers from 0 to n
    int XOR1 = 0;
    for (int i = 0; i <= n; i++)
    {
      XOR1 = XOR1 ^ i; // Cumulatively XOR all numbers
    }

    // XOR all elements in the array
    int XOR2 = 0;
    for (int i = 0; i < n; i++)
    {
      XOR2 = XOR2 ^ nums[i]; // Cumulatively XOR all array elements
    }

    // The missing number is the XOR of XOR1 and XOR2
    return XOR1 ^ XOR2;
  }
};

/*
 * Approach-4: XOR Method "Modified" (Optimal Solution)
 * - XOR all numbers from 0 to n (inclusive) while simultaneously XORing elements of the array in the same loop.
 * - This approach reduces the number of loops by combining the computation of `XOR1` and `XOR2`.
 * - The missing number is determined by taking the XOR of the results, as numbers appearing in both sequences cancel out, leaving the missing number.
 * ----------------------------
 * T.C: O(n)
 * - The loop runs O(n) times as it combines the XOR operations for both numbers and elements of the array.
 * - Constants: The loop involves linear traversal with XOR operations.
 * ----------------------------
 * S.C: O(1)
 * - Only a constant amount of extra space is used for variables (`XOR1` and `XOR2`).
 */
class Solution
{
public:
  int missingNumber(vector<int> &nums)
  {
    // Get the size of the array
    int n = nums.size();

    // Initialize XOR1 for numbers and XOR2 for array elements
    int XOR1 = 0, XOR2 = 0;

    // Combine the computation of XOR1 and XOR2 in the same loop
    for (int i = 0; i < n; i++)
    {
      XOR2 = XOR2 ^ nums[i]; // XOR elements of the array
      XOR1 = XOR1 ^ i;       // XOR numbers from 0 to n-1
    }

    // Add n to XOR1 for the final computation
    XOR1 = XOR1 ^ n;

    // The missing number is the XOR of XOR1 and XOR2
    return XOR1 ^ XOR2;
  }
};
