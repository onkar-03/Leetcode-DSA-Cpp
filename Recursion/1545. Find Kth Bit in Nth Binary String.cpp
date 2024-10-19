#include <bits/stdc++.h>
using namespace std;

// Approach - Recursion
// T.C : O(log(k))
// S.C : O(log(k))) of system stack
class Solution
{
public:
  char findKthBit(int n, int k)
  {
    // Calculate the length of the nth sequence: length (2^n - 1).
    // This uses a bitwise left shift to efficiently calculate 2^n: (1 << n) shifts 1 by n bits to the left, which is equivalent to 2^n. Subtracting 1 gives us the length of the sequence, (2^n - 1).
    // EG: pow(2,n)-1 = (1 << n) - 1
    int length = (1 << n) - 1;

    // Base case: If n == 1, the first sequence S_1 is just "0"
    if (n == 1)
    {
      return '0';
    }

    // If k is in the first half of the sequence (before the middle bit),
    // recursively search in the previous sequence (S_{n-1}).
    if (k <= length / 2)
    {
      // Return the kth bit from S_{n-1}
      return findKthBit(n - 1, k);
    }
    // If k is the middle bit of the sequence (the (length / 2 + 1)-th bit), then this bit is always '1' for all n >= 2.
    else if (k == length / 2 + 1)
    {
      return '1';
    }
    // If k is in the second half of the sequence (after the middle bit), we need to find the mirrored bit from the first half, flip it, and return it.
    else
    {
      // Find the corresponding bit from the first half by flipping the index:
      // (length - (k - 1)) gives the mirrored index.
      char ch = findKthBit(n - 1, length - (k - 1));

      // Flip the bit (if it's '0', change to '1'; if it's '1', change to '0').
      return (ch == '0') ? '1' : '0';
    }
  }
};
