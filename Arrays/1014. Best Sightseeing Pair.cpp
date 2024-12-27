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

// Approach-2 (Using extra space)
// Time Complexity: O(n) - We make two passes over the array: one to fill 'vec' and another to calculate the result.
// Space Complexity: O(n) - We use an additional array 'vec' to store intermediate results.

class Solution
{
public:
  int maxScoreSightseeingPair(vector<int> &values)
  {
    // n represents the size of the input array 'values'
    int n = values.size();

    // 'vec' array will store the maximum value of (values[i] + i) for all indices i
    vector<int> vec(n, 0);

    // Initialize vec[0] to values[0] + 0 as the base case
    vec[0] = values[0] + 0;

    // Fill 'vec' with the maximum value of (values[i] + i) up to index i
    for (int i = 1; i < n; i++)
    {
      // At each index i, store the maximum of (values[i] + i) and the previous maximum value in vec[i-1]
      vec[i] = max(values[i] + i, vec[i - 1]);
    }

    // 'result' will hold the maximum score for any pair (i, j)
    int result = 0;

    // Iterate over each possible second index j in the pair
    for (int j = 1; j < n; j++)
    {
      // 'x' is the score of the second element in the pair (values[j] - j)
      int x = values[j] - j;

      // 'y' is the maximum value of (values[i] + i) for all i < j, which is stored in vec[j-1]
      int y = vec[j - 1];

      // Calculate the score for the current pair (i, j) and update 'result' if it's higher
      result = max(result, x + y);
    }

    // Return the maximum score found
    return result;
  }
};
