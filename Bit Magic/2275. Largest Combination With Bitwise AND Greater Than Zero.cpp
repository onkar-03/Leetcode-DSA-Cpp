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

    // Loop through each bit position from 0 to 23 (since numbers fit within 24 bits)
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
