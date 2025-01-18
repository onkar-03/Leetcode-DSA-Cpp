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

// Approach-2: Dijkstra's Algorithm - Accepted Solution
// Time Complexity: O((m*n) * log(m*n)), where m and n are the grid dimensions.
// For each cell, we may process it once in the priority queue, and heap operations (push/pop) take O(log(m*n)).
// Space Complexity: O(m*n), for the result matrix and priority queue.
class Solution
{
public:
  // Define movement directions: right, left, down, up
  vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int minCost(vector<vector<int>> &grid)
  {
    int m = grid.size();    // Number of rows in the grid
    int n = grid[0].size(); // Number of columns in the grid

    // Min-heap to store {cost, row, col}, sorted by cost
    priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

    // Result matrix to track minimum cost to reach each cell
    vector<vector<int>> result(m, vector<int>(n, INT_MAX));

    // Initialize priority queue and result matrix for the starting cell
    pq.push({0, 0, 0}); // Starting cell with cost = 0
    result[0][0] = 0;

    // Perform Dijkstra's algorithm
    while (!pq.empty())
    {
      auto curr = pq.top(); // Get the cell with the smallest cost
      pq.pop();

      int currCost = curr[0]; // Current path cost
      int i = curr[1];        // Current row
      int j = curr[2];        // Current column

      // If the current cost is already higher than the recorded cost, skip
      if (result[i][j] < currCost)
      {
        continue;
      }

      // Explore all 4 possible directions
      for (int dir_i = 0; dir_i <= 3; dir_i++)
      {
        int i_ = i + dir[dir_i][0]; // Calculate new row
        int j_ = j + dir[dir_i][1]; // Calculate new column

        // Check if the new cell is within bounds
        if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n)
        {
          int gridDir = grid[i][j]; // Direction in the current cell
          // Calculate cost for this direction
          int dirCost = ((gridDir - 1 != dir_i) ? 1 : 0);

          int newCost = currCost + dirCost; // Total cost to move to the new cell

          // If the new cost is lower than the recorded cost, update
          if (newCost < result[i_][j_])
          {
            result[i_][j_] = newCost;   // Update the result matrix
            pq.push({newCost, i_, j_}); // Push the new cell to the priority queue
          }
        }
      }
    }

    // Return the minimum cost to reach the bottom-right cell (m-1, n-1)
    return result[m - 1][n - 1];
  }
};