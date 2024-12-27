#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// Time Complexity: O(n^2) - Nested loops result in a quadratic time complexity.
// Space Complexity: O(1) - No additional space is used apart from a few variables.
class Solution
{
public:
  int maxScoreSightseeingPair(vector<int> &values)
  {
    // Size of the input array 'values'
    int n = values.size();

    // 'result' will store the maximum score encountered
    int result = 0;

    // Outer loop iterates over the second element (j) in the pair
    for (int j = 1; j < n; j++)
    {
      // 'max_val' will store the maximum value for the first element (i) up to index j-1
      int max_val = 0;

      // Inner loop iterates over all possible first elements (i) for the current j
      for (int i = j - 1; i >= 0; i--)
      {
        // Update 'max_val' by calculating values[i] + i (score for the first element)
        // We try to find the best 'i' that maximizes the score for the pair
        max_val = max(max_val, values[i] + i);
      }

      // Calculate the score for the pair (i, j) as max_val + values[j] - j
      // Update the result if this pair gives a better score
      result = max(result, max_val + values[j] - j);
    }

    // Return the maximum score found
    return result;
  }
};
