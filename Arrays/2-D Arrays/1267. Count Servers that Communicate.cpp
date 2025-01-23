#include <bits/stdc++.h>
using namespace std;

/*
 * Approach - 1 (Brute Force)
 * ---------------------------
 * Traverse every cell in the grid. If a server is found, check all other servers in the same row
 * and then in the same column to determine if it can communicate with another server.
 * ---------------------------
 * Time Complexity: O((m * n) * (m + n))
 * - We iterate through each cell in the grid (O(m * n)).
 * - For every server, we check all other servers in its row and column (O(m + n)).
 * ---------------------------
 * Space Complexity: O(1)
 * - No extra space is used apart from variables for counting and tracking communication.
 */

class Solution
{
public:
  int countServers(vector<vector<int>> &grid)
  {
    int m = grid.size(), n = grid[0].size(); // Dimensions of the grid
    int resultServers = 0;                   // Counter for servers that can communicate

    // Traverse through the grid
    for (int row = 0; row < m; ++row)
    {
      for (int col = 0; col < n; ++col)
      {
        // If there is a server at this position
        if (grid[row][col] == 1)
        {
          bool canCommunicate = false; // Tracks communication status

          // Check the current row for other servers
          for (int otherCol = 0; otherCol < n; ++otherCol)
          {
            if (otherCol != col && grid[row][otherCol] == 1)
            {
              canCommunicate = true; // Found another server in the same row
              break;                 // Exit loop since communication is confirmed
            }
          }

          // If no communication was found in the row, check the column
          if (!canCommunicate)
          {
            for (int otherRow = 0; otherRow < m; ++otherRow)
            {
              if (otherRow != row && grid[otherRow][col] == 1)
              {
                canCommunicate = true; // Found another server in the same column
                break;                 // Exit loop since communication is confirmed
              }
            }
          }

          // If the server can communicate, increment the counter
          if (canCommunicate)
          {
            resultServers++;
          }
        }
      }
    }

    // Return the count of servers that can communicate
    return resultServers;
  }
};
