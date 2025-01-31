#include <bits/stdc++.h>
using namespace std;

// Approach - 1 - Brute Force DFS (you can do BFS as well)
// T.C : O(n^4)
// S.C : O(n^2)
class Solution
{
public:
  int m, n;                                                         // Grid dimensions
  vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // Possible moves

  // DFS function to compute island size and mark its ID
  int DFS(vector<vector<int>> &grid, int i, int j, int &id)
  {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1)
      return 0; // Out of bounds or already visited

    grid[i][j] = id; // Mark current cell with island ID
    int count = 1;   // Start with one cell

    // Explore all 4 directions
    for (vector<int> &dir : directions)
    {
      int x = i + dir[0];           // Move in x direction
      int y = j + dir[1];           // Move in y direction
      count += DFS(grid, x, y, id); // Recursively count island size
    }

    return count;
  }

  // Main function to find the largest island
  int largestIsland(vector<vector<int>> &grid)
  {
    m = grid.size();
    n = grid[0].size();
    int maxArea = 0;
    unordered_map<int, int> mp; // Store island ID -> size
    int island_id = 2;          // Start marking islands from ID 2

    // First pass: Identify islands and store their sizes
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {                                        // Found an unvisited island
          int size = DFS(grid, i, j, island_id); // Mark and get size
          maxArea = max(maxArea, size);          // Track the largest island
          mp[island_id] = size;                  // Store size in map
          island_id++;                           // Increment ID for next island
        }
      }
    }

    // Second pass: Try converting '0' to '1' and check max area
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 0)
        {                        // Only process empty cells
          unordered_set<int> st; // Store unique neighboring islands

          // Check all 4 neighbors
          for (vector<int> &dir : directions)
          {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 0)
              st.insert(grid[x][y]); // Store unique island IDs
          }

          int sum = 1; // Convert '0' to '1', so start with size 1
          for (const int &s : st)
          {
            sum += mp[s]; // Add sizes of neighboring islands
          }
          maxArea = max(maxArea, sum); // Update max area
        }
      }
    }

    return maxArea; // Return the maximum island size possible
  }
};
