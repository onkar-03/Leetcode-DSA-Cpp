#include <bits/stdc++.h>
using namespace std;

// Approach-1: Using Recursion with Memoization
// Time Complexity: O(n * k + m * k)
// Space Complexity: O(m * k)
// n = number of words, k = length of each word, m = length of the target string.

class Solution
{
public:
  int m;                   // Length of the target string.
  int k;                   // Length of each word (number of columns in the frequency matrix).
  const int MOD = 1e9 + 7; // Modulo value to handle large results.
  int t[1001][1001];       // DP table to store results of subproblems.

  // Recursive function to calculate the number of ways to form the target string.
  int solve(int i, int j, vector<vector<long long>> &freq, string &target)
  {
    // Base case: If we have formed the entire target string, return 1.
    if (i == m)
      return 1;

    // Base case: If we have exhausted all columns in the words, return 0.
    if (j == k)
      return 0;

    // If the result is already computed, return it (Memoization).
    if (t[i][j] != -1)
      return t[i][j];

    // Case 1: Skip the current column and move to the next column.
    int not_taken = solve(i, j + 1, freq, target) % MOD;

    // Case 2: Take the current column if the character matches the target.
    int taken = (freq[target[i] - 'a'][j] * solve(i + 1, j + 1, freq, target)) % MOD;

    // Store the result in the DP table and return it.
    return t[i][j] = (not_taken + taken) % MOD;
  }

  // Main function to calculate the number of ways to form the target string.
  int numWays(vector<string> &words, string target)
  {
    k = words[0].size(); // Number of columns in the frequency matrix.
    m = target.length(); // Length of the target string.

    // Step 1: Build the frequency matrix.
    // freq[c][col] stores the count of character `c` at column `col` in `words`.
    vector<vector<long long>> freq(26, vector<long long>(k, 0));
    for (int col = 0; col < k; col++)
    {
      for (string &word : words)
      {
        freq[word[col] - 'a'][col]++;
      }
    }

    // Step 2: Initialize the DP table with -1 to signify uncomputed states.
    memset(t, -1, sizeof(t));

    // Step 3: Start the recursive function to calculate the result.
    return solve(0, 0, freq, target);
  }
};
