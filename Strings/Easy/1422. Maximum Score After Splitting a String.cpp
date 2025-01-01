#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// Time Complexity: O(n^2) - Due to nested loops for calculating zeros and ones.
// Space Complexity: O(1) - No additional space used apart from variables.
class Solution
{
public:
  int maxScore(string s)
  {
    int n = s.length(); // Get the length of the input string.

    int result = INT_MIN; // Initialize the maximum score to the smallest possible value.

    // Iterate through all possible split points (from 0 to n-2).
    for (int i = 0; i < n - 1; i++)
    {
      int zeros_left = 0; // Count of zeros in the left part of the split.

      // Count zeros in the substring from the start to the current split point.
      for (int j = 0; j <= i; j++)
      {
        if (s[j] == '0')
        {
          zeros_left++; // Increment the count for each '0' encountered.
        }
      }

      int ones_right = 0; // Count of ones in the right part of the split.

      // Count ones in the substring from the split point + 1 to the end.
      for (int j = i + 1; j < n; j++)
      {
        if (s[j] == '1')
        {
          ones_right++; // Increment the count for each '1' encountered.
        }
      }

      // Update the result with the maximum score so far.
      result = max(result, zeros_left + ones_right);
    }

    // Return the maximum score after evaluating all split points.
    return result;
  }
};
