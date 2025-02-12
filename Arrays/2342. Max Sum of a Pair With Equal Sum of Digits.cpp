#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Brute Force
 * - Iterate through each pair of numbers in the array.
 * - Compute the sum of digits for both numbers.
 * - If two numbers have the same sum of digits, compute their sum and track the maximum.
 *
 * T.C: O(N^2)
 * - For each number, we compute the digit sum (O(log(num))).
 * - We compare each pair, leading to O(N^2) complexity.
 *
 * S.C: O(1)
 * - Only a few integer variables are used, so space usage is constant.
 * ----------------------------
 */

class Solution
{
public:
  // Function to compute the sum of digits of a number
  int getDigitSum(int num)
  {
    int sum = 0;
    while (num > 0)
    {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }

  int maximumSum(vector<int> &nums)
  {
    // Get the size of the input array
    int n = nums.size();

    // Initialize result to -1 (in case no valid pair exists)
    int result = -1;

    // Iterate through each pair of numbers in the array
    for (int i = 0; i < n; i++)
    {
      int digitSumi = getDigitSum(nums[i]);

      for (int j = i + 1; j < n; j++)
      {
        int digitSumj = getDigitSum(nums[j]);

        // Check if both numbers have the same digit sum
        if (digitSumi == digitSumj)
        {
          // Update the result if sum is greater
          result = max(result, nums[i] + nums[j]);
        }
      }
    }
    return result;
  }
};

/*
 * Approach-2: Unordered Map Hashing
 * - Use an unordered map to track the largest number for each digit sum.
 * - If a number with the same digit sum already exists in the map, compute the sum and update the maximum result.
 * - Update the map with the maximum value for that digit sum.
 *
 * T.C: O(N * log(num))
 * - We iterate through the array once (O(N)), and for each number, we compute its digit sum (O(log(num))).
 *
 * S.C: O(N)
 * - In the worst case, we store all elements in the map.
 * ----------------------------
 */

class Solution
{
public:
  int getDigitSum(int num)
  {
    int sum = 0;
    while (num > 0)
    {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }

  int maximumSum(vector<int> &nums)
  {
    int n = nums.size();

    // Stores the max number for each digit sum
    unordered_map<int, int> mp;

    // Initialize result to -1 (in case no valid pair exists)
    int result = -1;

    for (int i = 0; i < n; i++)
    {
      int digitSum = getDigitSum(nums[i]);

      // If a number with the same digit sum exists, compute max sum
      if (mp.count(digitSum))
      {
        result = max(result, nums[i] + mp[digitSum]);
      }

      // Update the map with the maximum number for this digit sum
      mp[digitSum] = max(mp[digitSum], nums[i]);
    }
    return result;
  }
};

/*
 * Approach-3 (Optimal array as Map of constant size)
 * - Use an array of fixed size (82) to store the largest number for each digit sum.
 * - If a number with the same digit sum exists, compute the sum and update the maximum result.
 * - Update the array with the maximum value for that digit sum.
 *
 * T.C: O(N * M)
 * - We iterate through the array once (O(N)), and for each number, we compute its digit sum (O(M)),
 *   where M is the number of digits in the largest number (≈ log(num)).
 *
 * S.C: O(1)
 * - The extra space used is constant (array of size 82).
 * ----------------------------
 */

class Solution
{
public:
  int getDigitSum(int num)
  {
    int sum = 0;

    while (num > 0)
    {
      sum += (num % 10);
      num /= 10;
    }

    return sum;
  }

  int maximumSum(vector<int> &nums)
  {
    int n = nums.size();

    // Initialize result to -1 (in case no valid pair exists)
    int result = -1;

    // Array used as a fixed-size map for storing max number per digit sum
    int mp[82] = {0};

    for (int i = 0; i < n; i++)
    {
      int digitSum = getDigitSum(nums[i]);

      // If a number with the same digit sum exists, compute max sum
      if (mp[digitSum] > 0)
      {
        result = max(result, nums[i] + mp[digitSum]);
      }

      // Update the array with the maximum number for this digit sum
      mp[digitSum] = max(mp[digitSum], nums[i]);
    }

    return result;
  }
};
