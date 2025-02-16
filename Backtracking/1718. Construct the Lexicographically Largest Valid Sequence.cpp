#include <bits/stdc++.h>
using namespace std;

/*
 * Approach: Recusion + Memoization
 * - We use backtracking to construct the lexicographically largest valid sequence.
 * - We attempt to place numbers from `n` to `1` at valid positions.
 * - If a number `num` is placed at index `i`, then `num` should also be placed at `i + num`
 *   (except for `1`, which appears only once).
 * - If a valid placement is not possible, we backtrack and try the next possibility.
 * ----------------------------
 * T.C: O(n!) (Factorial Complexity)
 * - The worst case involves exploring multiple permutations of numbers.
 * ----------------------------
 * S.C: O(n) (Recursive Stack + Used Array)
 * - We use an array to track used numbers and recursion stack space.
 */

class Solution
{
public:
  bool solve(int i, int n, vector<int> &result, vector<bool> &used)
  {
    // Base case: If we have filled all positions, return true
    if (i >= result.size())
    {
      return true; // Guaranteed answer as we filled the largest element first
    }

    // If the current index is already filled, move to the next index
    if (result[i] != -1)
    {
      return solve(i + 1, n, result, used);
    }

    // Try placing numbers from n to 1
    for (int num = n; num >= 1; num--)
    {
      // Skip if the number is already used
      if (used[num])
      {
        continue;
      }

      // Mark the number as used and place it at index i
      used[num] = true;
      result[i] = num;

      // Special case: If the number is 1, we only place it once
      if (num == 1)
      {
        if (solve(i + 1, n, result, used))
        {
          return true;
        }
      }
      else
      {
        // Calculate the second position where 'num' should be placed
        int j = i + num;

        // Ensure the second position is valid and empty
        if (j < result.size() && result[j] == -1)
        {
          result[j] = num;

          // Recur to place the remaining numbers
          if (solve(i + 1, n, result, used))
          {
            return true;
          }

          // Backtrack: Undo the placement at j
          result[j] = -1;
        }
      }

      // Backtrack: Undo the placement at i and mark the number as unused
      result[i] = -1;
      used[num] = false;
    }

    return false; // No valid placement found
  }

  vector<int> constructDistancedSequence(int n)
  {
    // Used array to track placed numbers
    vector<bool> used(n + 1, false);

    // Result array initialized with -1
    vector<int> result(2 * n - 1, -1);

    // Start backtracking from index 0
    solve(0, n, result, used);

    return result;
  }
};
