#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

// Approach 1 : (Normal DFS Without Memoization) TLE
// TC: O(3^(m * n)),
// SC: O(m *n)
class Solution
{
public:
  int m, n;                         // Dimensions of the grid (rows and columns)
  vector<int> directions{-1, 0, 1}; // Direction vector to move up, right, and down diagonally in columns

  // DFS function to find the longest increasing path starting from (row, col)
  int DFS(int row, int col, vector<vector<int>> &grid)
  {
    int moves = 0; // Initialize moves for this path

    // Loop over directions (up-right, right, down-right)
    for (int &dir : directions)
    {
      int newRow = row + dir; // Calculate new row position based on direction
      int newCol = col + 1;   // Move to the next column to the right

      // Check if newRow and newCol are within bounds and if the value at new position is greater
      if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > grid[row][col])
      {
        // Recursive DFS call to find the max moves from the new position, add 1 move for the current step
        moves = max(moves, 1 + DFS(newRow, newCol, grid));
      }
    }
    // Return the maximum moves found from this position
    return moves;
  }

  int maxMoves(vector<vector<int>> &grid)
  {
    m = grid.size();    // Get the number of rows
    n = grid[0].size(); // Get the number of columns

    int result = 0; // Initialize the result to store the maximum moves

    // Loop over each row in the first column as the starting point
    for (int row = 0; row < m; row++)
    {
      // Call DFS for each starting position and update result
      result = max(result, DFS(row, 0, grid));
    }

    // Return the maximum moves possible from any starting row in the first column
    return result;
  }
};

// Approach 2 : (DFS with Memoization)
// TC: O(m * n)
// SC: O(m *n)
class Solution
{
public:
  int m, n; // Dimensions of the grid (rows and columns)
  // Direction vector to move up-right, right, and down-right in columns
  vector<int> directions{-1, 0, 1};

  int DFS(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &t) // Pass memoization table 't' by reference
  {
    // Check if the value is already computed to avoid redundant calculations
    if (t[row][col] != -1)
    {
      return t[row][col];
    }

    // Initialize moves for this path
    int moves = 0;

    // Loop over directions (up-right, right, down-right)
    for (int &dir : directions)
    {
      int newRow = row + dir; // Calculate new row position based on direction
      int newCol = col + 1;   // Move to the next column to the right

      // Check if newRow and newCol are within bounds and if the value at new position is greater
      if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] > grid[row][col])
      {
        // Recursive DFS call to find the max moves from the new position, add 1 move for the current step
        moves = max(moves, 1 + DFS(newRow, newCol, grid, t));
      }
    }

    // Store the computed result in the memoization table
    t[row][col] = moves;
    // Return the maximum moves found from this position
    return moves;
  }

  int maxMoves(vector<vector<int>> &grid)
  {
    m = grid.size();    // Get the number of rows
    n = grid[0].size(); // Get the number of columns

    // Initialize memoization table with -1
    // Create 2D Vector with m rows and n columns in each row all with value -1
    vector<vector<int>> t(m, vector<int>(n, -1));

    // Initialize the result to store the maximum moves
    int result = 0;

    // Loop over each row in the first column as the starting point
    for (int row = 0; row < m; row++)
    {
      // Call DFS for each starting position and update result
      result = max(result, DFS(row, 0, grid, t));
    }

    // Return the maximum moves possible from any starting row in the first column
    return result;
  }
};