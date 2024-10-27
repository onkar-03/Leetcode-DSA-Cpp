#include <bits/stdc++.h>
using namespace std;

// Question Same as Maximal Square (Leetcode-221)
// Approach - 1 (Simple Recursion no Memoization)
// Time Complexity: O(3^(m+n)) or O(2^(m+n))
// Space Complexity: O(m + n) due to the recursive call stack depth.

class Solution
{
public:
  int m, n; // Variables to store the number of rows (m) and columns (n) of the grid

  // Recursive function to solve the problem
  int solve(int i, int j, vector<vector<int>> &grid)
  {
    // Base case: If the current indices are out of bounds
    if (i >= m || j >= n)
      return 0;

    // If the current cell is 0, return 0 as it cannot contribute to squares
    if (grid[i][j] == 0)
      return 0;

    // Recursive calls to explore right, diagonal, and below cells
    int right = solve(i, j + 1, grid);        // Right cell
    int diagonal = solve(i + 1, j + 1, grid); // Diagonal cell
    int below = solve(i + 1, j, grid);        // Below cell

    // Return the Result: count of squares formed at this position
    return 1 + min({right, diagonal, below});
  }

  // Function to count the number of squares
  int countSquares(vector<vector<int>> &grid)
  {
    int result = 0;     // Variable to hold the final count of squares
    m = grid.size();    // Get the number of rows in the grid
    n = grid[0].size(); // Get the number of columns in the grid

    // Iterate through each cell in the grid
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        // Only process cells that are 1, as they can contribute to squares
        if (grid[i][j] == 1)
        {
          // Accumulate the count of squares for each cell
          result += solve(i, j, grid);
        }
      }
    }
    // Return the final count of squares
    return result;
  }
};

// Approach - 2 (simple Recursion Memoization) - Same as Maximal Square (Leetcode-221)
// Time Complexity: O(m*n)
// Space Complexity: O(m * n) due to the memoization table
class Solution
{
public:
  int m, n; // Variables to store the number of rows (m) and columns (n) of the grid

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
    vector<vector<int>> t(m + 1, vector<int>(n + 1, -1));

    // Iterate through each cell in the grid
    for (int i = 0; i < grid.size(); i++)
    {
      for (int j = 0; j < grid[0].size(); j++)
      {
        // Accumulate the count of squares for each cell
        result += solve(i, j, grid, t);
      }
    }
    // Return the final count of squares
    return result;
  }
};
