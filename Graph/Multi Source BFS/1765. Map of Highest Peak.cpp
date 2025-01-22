#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(m * n)
- Each cell in the grid is visited exactly once, either as a water cell or during BFS.
- BFS processes all neighboring cells of each cell, but each cell is visited only once, resulting in O(m * n)

Space Complexity: O(m * n)
- The height grid requires O(m * n) space to store the results.
- The queue can contain all cells in the worst case, requiring O(m * n) space.
*/
class Solution
{
public:
  // Define a type alias for pair<int, int> to improve readability
  typedef pair<int, int> P;

  // Define the four possible directions for BFS traversal
  vector<vector<int>> directions{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

  // Function to calculate the highest peak grid using Multi-Source BFS
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
  {
    // Get the dimensions of the input grid
    int m = isWater.size();
    int n = isWater[0].size();

    // Initialize the height grid with -1 (unvisited)
    vector<vector<int>> height(m, vector<int>(n, -1));

    // Queue to perform BFS, storing cells as pairs of coordinates
    queue<P> que;

    // Populate the queue with water cells and set their height to 0
    // T.C: O(m * n)
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (isWater[i][j] == 1)
        {                   // This cell is water
          height[i][j] = 0; // Water cells start with height 0
          que.push({i, j}); // Push water cells as BFS starting points
        }
      }
    }

    // Perform Level Wise BFS to calculate heights for land cells
    // T.C : O(m*n)
    // S.C : O(m*n)
    while (!que.empty())
    {
      // Get the number of cells in the current BFS level
      int N = que.size();

      // Process all cells at the current BFS level
      while (N--)
      {
        P curr = que.front();
        que.pop();

        int i = curr.first;  // Current cell's row index
        int j = curr.second; // Current cell's column index

        // Traverse in all four directions
        for (auto &dir : directions)
        {
          int i_ = i + dir[0]; // New row index
          int j_ = j + dir[1]; // New column index

          // Check if the new cell is within bounds and unvisited
          if (i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && height[i_][j_] == -1)
          {
            height[i_][j_] = height[i][j] + 1; // Update height for the new cell
            que.push({i_, j_});                // Add the new cell to the queue for BFS
          }
        }
      }
    }

    // Return the final height grid
    return height;
  }
};
