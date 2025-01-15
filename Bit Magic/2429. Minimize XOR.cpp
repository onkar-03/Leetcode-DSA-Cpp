#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Starting from num1 and then forming result)

// Time Complexity: O(log(n)) where 'n' is the number of bits in the integers
// For any number the number of bits required to represent it is Log(n)
// Hence in worst case we traverse the whole number i.e. log(n)

// Space Complexity: O(1) as the solution modifies the input number in place

class Solution
{
public:
  // Function to check if the bit at the given position 'bit' is set (1)
  bool isSet(int x, int bit)
  {
    return x & (1 << bit); // If the bit at position 'bit' is 1, return true
  }

  // Function to set the bit at position 'bit' to 1
  void setBit(int &x, int bit)
  {
    x |= (1 << bit); // Perform bitwise OR to set the 'bit' to 1
  }

  // Function to unset (clear) the bit at position 'bit' to 0
  void unsetBit(int &x, int bit)
  {
    x &= ~(
        1
        << bit); // Perform bitwise AND with negation to set the 'bit' to 0
  }

  // Function to minimize the XOR of two integers by adjusting the number of
  // set bits
  int minimizeXor(int num1, int num2)
  {
    int x = num1; // Start with num1 as the initial value

    // Count the number of set bits (1's) in num2 and num1 using
    // __builtin_popcount
    int requiredSetBits = __builtin_popcount(
        num2); // The desired number of set bits in the result
    int currentSetBits =
        __builtin_popcount(x); // The current number of set bits in x

    int bit = 0; // Bit position starts from 0 (rightmost bit)

    // If current set bits in 'x' are fewer than required set bits, we need
    // to add more set bits
    if (currentSetBits < requiredSetBits)
    {
      while (currentSetBits < requiredSetBits)
      {
        // If the bit at 'bit' position is not set, set it to 1
        if (!isSet(x, bit))
        {
          setBit(x, bit);   // Set the bit at 'bit' position
          currentSetBits++; // Increment the count of set bits
        }
        bit++; // Move to the next bit position
      }
    }
    // If current set bits in 'x' are more than required, we need to remove
    // some set bits
    else if (currentSetBits > requiredSetBits)
    {
      while (currentSetBits > requiredSetBits)
      {
        // If the bit at 'bit' position is already set (1), unset it
        // (set to 0)
        if (isSet(x, bit))
        {
          unsetBit(x, bit); // Unset the bit at 'bit' position
          currentSetBits--; // Decrement the count of set bits
        }
        bit++; // Move to the next bit position
      }
    }

    return x; // Return the modified value of 'x' that minimizes the XOR
              // with num2
  }
};
