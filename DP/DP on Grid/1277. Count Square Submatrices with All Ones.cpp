#include <bits/stdc++.h>
using namespace std;

// Approach - 1 (simple Recursion Memoization) - Same as Maximal Square (Leetcode-221)
// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

class Solution
{
public:
  int m, n; // Variables to store the number of rows (m) and columns (n) of the grid

  // Recursive function to solve the problem
  int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &t)
  {

    // Base case: If the current indices are out of bounds
    if (i >= grid.size() || j >= grid[0].size())
      return 0;

    // If the current cell is 0, return 0 as it cannot contribute to squares
    if (grid[i][j] == 0)
      return 0;

    // If the value is already computed, return it from the memoization table
    if (t[i][j] != -1)
      return t[i][j];

    // Recursive calls to explore right, diagonal, and below cells
    int right = solve(i, j + 1, grid, t);        // Right cell
    int diagonal = solve(i + 1, j + 1, grid, t); // Diagonal cell
    int below = solve(i + 1, j, grid, t);        // Below cell

    // Store the computed result in the memoization table and return it
    return t[i][j] = 1 + min({right, diagonal, below});
  }

  // Function to count the number of squares
  int countSquares(vector<vector<int>> &grid)
  {
    int result = 0;     // Variable to hold the final count of squares
    m = grid.size();    // Get the number of rows in the grid
    n = grid[0].size(); // Get the number of columns in the grid

    // Initialize the memoization table with -1
    vector<vector<int>> t(m, vector<int>(n, -1));

    // Iterate through each cell in the grid
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        // Accumulate the count of squares for each cell
        result += solve(i, j, grid, t);
      }
    }
    return result; // Return the final count of squares
  }
};
