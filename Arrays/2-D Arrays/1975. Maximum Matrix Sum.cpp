#include <bits/stdc++.h>
using namespace std;

// Approach: Check if the count of negative numbers is odd or even.
// T.C: O(row * col) - Traverses all elements of the matrix.
// S.C: O(1) - Uses constant extra space.

class Solution
{
public:
  long long maxMatrixSum(vector<vector<int>> &matrix)
  {
    int m = matrix.size();    // Number of rows in the matrix.
    int n = matrix[0].size(); // Number of columns in the matrix.

    // Stores the total sum of absolute values of the elements.
    long long sum = 0;

    // Counts the number of negative elements in the matrix.
    int countNegatives = 0;

    // Tracks the smallest absolute value in the matrix.
    int smallestAbsoluteValue = INT_MAX;

    // Iterate over each element in the matrix.
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        // Add the absolute value of the current element to the total sum.
        sum += abs(matrix[i][j]); 

        // Increment the count if the current element is negative.
        if (matrix[i][j] < 0)
        {
          countNegatives++;
        }

        // Update the smallest absolute value found so far.
        smallestAbsoluteValue = min(smallestAbsoluteValue, abs(matrix[i][j]));
      }
    }

    // If the count of negative numbers is even, no adjustment is needed.
    // We can flip pairs of negatives to make all numbers non-negative.
    if (countNegatives % 2 == 0)
    {
      return sum;
    }

    // If the count of negative numbers is odd, one negative will remain.
    // Subtract twice the smallest absolute value to maximize the sum.
    return sum - 2 * smallestAbsoluteValue;
  }
};
