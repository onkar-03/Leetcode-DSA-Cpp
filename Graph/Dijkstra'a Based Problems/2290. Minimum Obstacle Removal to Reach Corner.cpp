#include <bits/stdc++.h>
using namespace std;

// Approach (Using Dijkstra's Algorithm - Assuming obstacle with edge weight 1 and empty with 0)
// T.C : O(m*n log(m*n))
// S.C : O(m*n)
class Solution
{
public:
#define P pair<int, pair<int, int>>
  // Define directions for moving up, down, left, and right
  vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int minimumObstacles(vector<vector<int>> &grid)
  {
    int m = grid.size();    // Number of rows
    int n = grid[0].size(); // Number of columns

    // `result[i][j]` stores the minimum number of obstacles to remove
    // to reach cell [i][j] starting from [0][0].
    vector<vector<int>> result(m, vector<int>(n, INT_MAX));
    result[0][0] = 0; // Starting point has no obstacles removed yet.

    // Min-heap priority queue to process cells with the smallest cost first
    // Each element is {weight, {row, col}}
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, {0, 0}}); // Push starting cell with weight 0

    // Perform Dijkstra's algorithm to find the minimum obstacle removal
    while (!pq.empty())
    {
      auto curr = pq.top(); // Get the cell with the smallest distance
      pq.pop();

      int d = curr.first;         // Current distance/obstacle count
      int i = curr.second.first;  // Current row
      int j = curr.second.second; // Current column

      // Explore all 4 possible directions
      for (auto &dir : directions)
      {
        int x = i + dir[0]; // New row
        int y = j + dir[1]; // New column

        // Skip invalid cells (out of grid bounds)
        if (x < 0 || x >= m || y < 0 || y >= n)
        {
          continue;
        }

        // Determine the weight (0 for empty cell, 1 for obstacle)
        int wt = (grid[x][y] == 1) ? 1 : 0;

        // If we find a shorter path to (x, y), update and push to the queue
        if (d + wt < result[x][y])
        {
          result[x][y] = d + wt;     // Update the minimum distance
          pq.push({d + wt, {x, y}}); // Push updated cell into the queue
        }
      }
    }

    // Return the minimum obstacles to reach the bottom-right corner
    return result[m - 1][n - 1];
  }
};
