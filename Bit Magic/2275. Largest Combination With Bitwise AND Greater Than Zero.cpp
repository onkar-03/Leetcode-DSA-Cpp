#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Counter Method to track bit frequencies)
// T.C : O(24 * n) ~= O(n)
// S.C : O(24) ~= O(1)
class Solution
{
public:
  int largestCombination(vector<int> &candidates)
  {
    // Initialize a counter array to track how many numbers have each bit set count[i] = how many numbers have the i-th bit set (0-indexed)
    vector<int> count(24, 0);

    // Variable to store the maximum count of set bits at any position
    int result = 0;

    // Loop through each bit position from 0 to 23 (since numbers fit within 24 bits)\
    // Number of Bits to represent a Number: Floor of Log2(N) + 1
    for (int i = 0; i < 24; i++) // O(24)
    {

      // For each bit position, check all numbers in the candidates array
      for (int &num : candidates) // O(n)
      {
        // Check if the i-th bit in the current number is set (1)
        if ((num & (1 << i)) != 0)
        {
          // Increment count if the i-th bit is set
          count[i]++;
        }
      }

      // Update result with the maximum count of set bits for any position
      result = max(result, count[i]);
    }

    // Return the maximum count of set bits for any bit position, representing the largest combination
    return result;
  }
};

// Approach-2 (Without using counter array)
// T.C : O(24 * n) ~= O(n)
// S.C : O(1)
class Solution
{
public:
  int largestCombination(vector<int> &candidates)
  {
    // Initialize the result variable to store the maximum count of set bits for any bit position
    int result = 0;

    // Loop through each bit position from 0 to 23 (as we're dealing with 24-bit numbers)
    for (int i = 0; i < 24; i++) // O(24)
    {
      // Variable to store the count of numbers with the i-th bit set
      int count_ith = 0;

      // For each number in the candidates array, check if the i-th bit is set
      for (int &num : candidates) // O(n)
      {
        // If the i-th bit is set in num (i.e., the result of bitwise AND is non-zero)
        if ((num & (1 << i)) != 0)
        {
          // Increment the count for this bit position
          count_ith += 1;
        }
      }

      // Update the result with the maximum value between the current result and the count of numbers with the i-th bit set
      result = max(result, count_ith);
    }

    // Return the largest count of set bits found across all bit positions
    return result;
  }
};