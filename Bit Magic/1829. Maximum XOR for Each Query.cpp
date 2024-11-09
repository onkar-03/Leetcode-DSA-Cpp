#include <bits/stdc++.h>
using namespace std;

// Approach: Using XOR properties to find the maximum XOR for each prefix
// Time Complexity: O(n) - we iterate through the array once
// Space Complexity: O(1) - only a fixed amount of extra space is used
class Solution
{
public:
  vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
  {
    // Get the size of the nums array
    int n = nums.size();

    // Result vector to store the maximum XOR for each prefix
    vector<int> result(n);

    // Step 1: Calculate the total XOR of all elements in nums
    int XOR = 0;
    for (int i = 0; i < n; i++)
    {
      // XORing each element with XOR gives the cumulative XOR
      XOR ^= nums[i];
    }

    // Create a mask where all bits are set to 1 up to maximumBit
    // This is used to "flip" bits to maximize the XOR value for k
    // Example: If maximumBit is 3, mask will be 111 (7 in binary)
    // Formula = (2^n - 1) in Binary which is same as (1 << maximumBit) - 1
    int mask = ((1 << maximumBit) - 1);

    // Loop through each prefix, adjusting XOR and calculating maximum XOR
    for (int i = 0; i < n; i++)
    {
      // This flips the bits of XOR, giving the maximum possible k for this prefix
      int k = XOR ^ mask;
      // Store k in the result array
      result.push_back(k);

      // Update XOR by removing the last element of the current prefix
      // Decrement and reduce the XOR by removing nums from the end
      XOR = (XOR ^ nums[n - 1 - i]);
    }

    return result;
  }
};

// XOR (Exclusive OR) Operation:
// XOR, or "Exclusive OR," is a binary operation that compares two bits.
// It returns 1 if the bits are different (one is 1, the other is 0) and 0 if the bits are the same (both are 1 or both are 0).

// Truth Table for XOR:
//   A | B | A XOR B
//  ---|---|--------
//   0 | 0 |   0
//   0 | 1 |   1
//   1 | 0 |   1
//   1 | 1 |   0

// Key Properties of XOR:
//
// 1. Self-Cancellation:
//    x ^ x = 0
//    XORing a number with itself results in 0, as each bit cancels out.
//    Example: 5 ^ 5 = 0

// 2. Identity Property:
//    x ^ 0 = x
//    XORing a number with 0 leaves it unchanged.
//    Example: 7 ^ 0 = 7

// 3. Commutative and Associative Properties:
//    XOR is commutative and associative, meaning the order or grouping of operations doesn't matter.
//    (a ^ b) ^ c = a ^ (b ^ c)
//    Example: (3 ^ 4) ^ 5 = 3 ^ (4 ^ 5)
