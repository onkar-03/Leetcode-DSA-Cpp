#include <bits/stdc++.h>
using namespace std;

// Question Same as Maximal Square (Leetcode-221)

// Approach - 1 (Simple Recursion no Memoization) gives TLE
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

// Approach - 3 (Simple Bottom Up - Same as Maximal Square (Leetcode-221))
// Time Complexity: O(m*n) - Each cell is processed once.
// Space Complexity: O(m*n) - Storage for the memoization table (2D array).

class Solution
{
public:
  int countSquares(vector<vector<int>> &matrix)
  {
    // Check for empty matrix
    if (matrix.size() == 0)
      return 0;

    int m = matrix.size();    // Number of rows in the matrix
    int n = matrix[0].size(); // Number of columns in the matrix

    // Initialize a 2D vector for storing the number of squares ending at (i,j)
    vector<vector<int>> t(m, vector<int>(n, 0));

    int result = 0; // Variable to hold the final count of squares

    // Iterate through each cell in the matrix
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        // If we are in the first row or first column, the value is same as the matrix
        if (i == 0 || j == 0)
        {
          t[i][j] = matrix[i][j];
        }
        else
        {
          // If the current cell in the matrix is 1, calculate the size of the square
          if (matrix[i][j] == 1)
          {
            // The size of the square is 1 plus the minimum of the three adjacent squares
            t[i][j] = 1 + min({t[i - 1][j], t[i][j - 1], t[i - 1][j - 1]});
          }
        }
        // Accumulate the count of squares found
        result += t[i][j];
      }
    }

    // Return the final count of squares
    return result;
  }
};
