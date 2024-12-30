#include <bits/stdc++.h>
using namespace std;

// Approach-1: Using Recursion with Memoization
// Time Complexity: O(H) - Each state is computed once due to memoization.
// Space Complexity: O(H) - For the recursion stack and memoization table.
class Solution
{
public:
  int ans;               // Variable to store the result.
  int L, H;              // Range boundaries [L, H] for valid string lengths.
  int Z, O;              // Lengths to increment by adding '0's and '1's, respectively.
  const int M = 1e9 + 7; // Modulo value to handle large results.

  // Recursive function to calculate the number of "good" strings.
  int solve(int l, vector<int> &t)
  {
    // Base case: If the current length exceeds the upper bound, return 0.
    if (l > H)
      return 0;

    // Return the memoized result if already computed.
    if (t[l] != -1)
    {
      return t[l];
    }

    // Check if the current length falls within the valid range [L, H].
    bool addOne = false;
    if (l >= L && l <= H)
    {
      addOne = true;
    }

    // Recursive calls:
    // 1. Try extending the string with `Z` (adding '0's).
    int take_zero = solve(l + Z, t);
    // 2. Try extending the string with `O` (adding '1's).
    int take_one = solve(l + O, t);

    // Store the result: Whether this length contributes + results from both options.
    return t[l] = (addOne + take_zero + take_one) % M;
  }

  // Main function to initialize variables and start the recursion.
  int countGoodStrings(int low, int high, int zero, int one)
  {
    ans = 0;  // Initialize the result.
    L = low;  // Lower bound of the range.
    H = high; // Upper bound of the range.
    Z = zero; // Increment length for adding '0's.
    O = one;  // Increment length for adding '1's.

    // Memoization table to store intermediate results.
    vector<int> t(H + 1, -1);

    // Start the recursion with an initial length of 0.
    return solve(0, t);
  }
};
