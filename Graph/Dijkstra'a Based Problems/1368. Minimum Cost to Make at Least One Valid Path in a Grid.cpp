#include <bits/stdc++.h>
using namespace std;

// Approach-1: Backtracking DFS to try all possible paths (BRUTE FORCE)
// Time Complexity: O(4^(m*n)), where m and n are the dimensions of the grid.
// Space Complexity: O(m*n), for the visited array and recursive stack space.
class Solution
{
public:
  // Define directions for movement: right, left, down, up
  vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int m, n; // Dimensions of the grid

  // DFS function to explore all paths and calculate the minimum cost
  int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited, int cost)
  {
    // Base case: if we reach the bottom-right corner, return the cost
    if (i == m - 1 && j == n - 1)
    {
      return cost;
    }

    // Mark the current cell as visited
    visited[i][j] = true;

    // Variable to track the minimum cost among all possible paths
    int minCost = INT_MAX;

    // Explore all four directions
    for (int dir_i = 0; dir_i <= 3; dir_i++)
    {
      // Calculate the next cell coordinates
      int i_ = i + dir[dir_i][0];
      int j_ = j + dir[dir_i][1];

      // Check if the next cell is within bounds and not visited
      if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && !visited[i_][j_])
      {
        // Calculate the cost of moving to the next cell
        // Add 1 to the cost if the current direction does not match the grid's direction
        int nextCost = cost + ((grid[i][j] - 1 != dir_i) ? 1 : 0);

        // Recursively explore the next cell and update the minimum cost
        minCost = min(minCost, dfs(i_, j_, grid, visited, nextCost));
      }
    }

    // Backtrack by marking the current cell as unvisited
    visited[i][j] = false;

    return minCost; // Return the minimum cost for the current path
  }

  // Main function to calculate the minimum cost
  int minCost(vector<vector<int>> &grid)
  {
    // Initialize grid dimensions
    m = grid.size();
    n = grid[0].size();

    // Create a visited array to track visited cells
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // Start DFS from the top-left corner with an initial cost of 0
    return dfs(0, 0, grid, visited, 0);
  }
};
