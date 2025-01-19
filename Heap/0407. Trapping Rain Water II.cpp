#include <bits/stdc++.h>
using namespace std;

// Approach: Using Min-Heap (Priority Queue)
// Time Complexity (T.C): O(m * n * log(m * n))
// - In the worst case, we traverse the entire matrix, which has m * n elements.
// - Operations like `pop()` and `push()` in the priority queue take O(log(m * n)) time in the worst case.

// Space Complexity (S.C): O(m * n)
// - This accounts for the space used by the priority queue and the visited array.
class Solution
{
public:
  // Typedef for readability: PP represents a pair of an integer height and its coordinates (row, col).
  typedef pair<int, pair<int, int>> PP;

  // Directions array to simplify movement to the 4 neighboring cells (left, right, down, up).
  vector<vector<int>> directions = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

  int trapRainWater(vector<vector<int>> &heightMap)
  {
    int n = heightMap.size();    // Number of rows
    int m = heightMap[0].size(); // Number of columns

    // Min-Heap to keep track of the boundary cells with their heights.
    priority_queue<PP, vector<PP>, greater<>> boundaryCells;

    // Visited array to avoid revisiting cells.
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // Step 1: Push all boundary cells into the heap
    for (int row = 0; row < n; row++)
    {
      // Process the leftmost column
      boundaryCells.push({heightMap[row][0], {row, 0}});
      visited[row][0] = true;

      // Process the rightmost column
      // Check to avoid duplicate processing if there's only one column
      if (m > 1)
      {
        boundaryCells.push({heightMap[row][m - 1], {row, m - 1}});
        visited[row][m - 1] = true;
      }
    }

    // for (int row = 0; row < n; row++)
    // {
    // Process the leftmost and rightmost columns.
    //   for (int col : {0, m - 1})
    //   {
    //     boundaryCells.push({heightMap[row][col], {row, col}});
    //     visited[row][col] = true; // Mark these cells as visited.
    //   }
    // }

    for (int col = 0; col < m; col++)
    {
      // Process the topmost row
      boundaryCells.push({heightMap[0][col], {0, col}});
      visited[0][col] = true;

      // Process the bottommost row
      // Check to avoid duplicate processing if there's only one row
      if (n > 1)
      {
        boundaryCells.push({heightMap[n - 1][col], {n - 1, col}});
        visited[n - 1][col] = true;
      }
    }

    // for (int col = 0; col < m; col++)
    // {
    // Process the topmost and bottommost rows.
    //   for (int row : {0, n - 1})
    //   {
    //     boundaryCells.push({heightMap[row][col], {row, col}});
    //     visited[row][col] = true; // Mark these cells as visited.
    //   }
    // }

    // Variable to store the total trapped water.
    int water = 0;

    // Step 2: Process cells in the Min-Heap
    while (!boundaryCells.empty())
    {
      // Get the cell with the smallest height.
      PP q = boundaryCells.top();
      boundaryCells.pop();

      int height = q.first;    // Current cell's height.
      int i = q.second.first;  // Current cell's row.
      int j = q.second.second; // Current cell's column.

      // Step 3: Check all 4 neighboring cells
      for (vector<int> &dir : directions)
      {
        int i_ = i + dir[0]; // Row index of the neighbor.
        int j_ = j + dir[1]; // Column index of the neighbor.

        // Check if the neighbor is within bounds and not visited.
        if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < m &&
            !visited[i_][j_])
        {

          // Calculate the water trapped at the neighbor

          // METHOD 1:
          // if (heightMap[i_][j_] - heightMap[i][j] < 0) {
          //     water += 0;
          // } else {
          //     water += heightMap[i_][j_] - heightMap[i][j];
          // }

          // METHOD 2:
          water += max(0, height - heightMap[i_][j_]);

          // Push the neighbor into the heap with an updated height.
          // The height of this cell becomes the max of its own height
          // and the current cell's height.
          boundaryCells.push(
              {max(heightMap[i_][j_], height), {i_, j_}});

          // Mark the neighbor as visited.
          visited[i_][j_] = true;
        }
      }
    }

    // Return the total amount of trapped water.
    return water;
  }
};
