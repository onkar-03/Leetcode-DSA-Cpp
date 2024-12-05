#include <bits/stdc++.h>
using namespace std;

// Approach: Brute Force with Backtracking and Memoization
// Time Complexity: Exponential in the worst case due to exploring all possible swaps, though memoization reduces redundant computations.
// Space Complexity: O(n^2) - Due to memoization, where ~O(n^2) unique states are possible.
class Solution
{
public:
  int n; // Length of the string
  bool solve(string &start, string &target, unordered_map<string, bool> &mp)
  {
    // Base Case: If `start` matches `target`, transformation is successful
    if (start == target)
    {
      return true;
    }

    // Memoization: If we have already computed this state, return the stored result
    if (mp.count(start))
    {
      return mp[start];
    }

    // Try all possible valid swaps for 'L' and 'R'
    for (int i = 0; i < start.length(); i++)
    {
      // Case 1: Handle 'L' movement to the left
      if (start[i] == 'L' && i > 0 && start[i - 1] == '_')
      {
        // Swap 'L' with the blank space to move it left
        swap(start[i], start[i - 1]);

        // Recursive call to check if this leads to a valid transformation
        if (solve(start, target, mp))
        {
          return true; // If transformation is valid, return true
        }

        // Backtrack: Undo the swap
        swap(start[i], start[i - 1]);
      }

      // Case 2: Handle 'R' movement to the right
      else if (start[i] == 'R' && i < n - 1 && start[i + 1] == '_')
      {
        // Swap 'R' with the blank space to move it right
        swap(start[i], start[i + 1]);

        // Recursive call to check if this leads to a valid transformation
        if (solve(start, target, mp))
        {
          return true; // If transformation is valid, return true
        }

        // Backtrack: Undo the swap
        swap(start[i], start[i + 1]);
      }
    }

    // If no valid transformation is found, mark the current state as false in the memoization map
    return mp[start] = false;
  }

  bool canChange(string start, string target)
  {
    n = start.length();              // Store the length of the string
    unordered_map<string, bool> mp;  // Memoization map to store previously computed states
    return solve(start, target, mp); // Start the recursive backtracking process
  }
};

// Approach (Optimal Using 2 Pointers)
// T.C : O(n)
// S.C : O(1)
// Approach: Two Pointers
// Time Complexity: O(n) - We traverse the `start` and `target` strings once.
// Space Complexity: O(1) - No extra space is used apart from the pointers.
class Solution
{
public:
  bool canChange(string start, string target)
  {
    int n = start.length(); // Get the length of the strings
    int i = 0;              // Pointer for the `start` string
    int j = 0;              // Pointer for the `target` string

    // Traverse both strings
    while (i < n || j < n)
    {
      // Move the `i` pointer to the next non-'_' character in `start`
      while (i < n && start[i] == '_')
      {
        i++;
      }

      // Move the `j` pointer to the next non-'_' character in `target`
      while (j < n && target[j] == '_')
      {
        j++;
      }

      // Corner Case:
      // If one pointer reaches the end of its string, both pointers must do so simultaneously.
      // Example: `start = "_L"`, `target = "LL"`
      //   - After processing: `i == 2` (end of `start`), but `j == 1` (not at the end of `target`).
      //   - Since `start` has no more characters, but `target` still has 'L', the transformation is invalid.
      //   - Thus, the condition `i == n && j == n` ensures no unmatched characters remain in either string.
      if (i == n || j == n)
      {
        return i == n && j == n; // Both pointers must be at the end for a valid transformation.
      }

      // If the characters at the current pointers don't match, transformation isn't possible
      if (start[i] != target[j])
      {
        return false;
      }

      // Check for invalid 'L' movement:
      // 'L' in `start` cannot appear to the right of its position in `target`
      if (start[i] == 'L' && i < j)
      {
        return false;
      }

      // Check for invalid 'R' movement:
      // 'R' in `start` cannot appear to the left of its position in `target`
      if (start[i] == 'R' && i > j)
      {
        return false;
      }

      // Move to the next character in both strings
      i++;
      j++;
    }

    // If we successfully traverse both strings without issues, return true
    return true;
  }
};
