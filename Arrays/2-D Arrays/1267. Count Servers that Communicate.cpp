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

/*
 * Approach - 2 (Better Approach using Preprocessing)
 * ---------------------------------------------------
 * Instead of checking all servers in the same row and column for each server,
 * preprocess the grid to count the number of servers in each row and column.
 * Use this precomputed data to check if a server can communicate.
 * ---------------------------------------------------
 * Time Complexity: O(m * n)
 * - The grid is traversed twice: once to preprocess row and column counts, and
 *   once to determine the servers that can communicate.
 * ---------------------------------------------------
 * Space Complexity: O(m + n)
 * - We use two arrays to store the count of servers in each row and column.
 */

class Solution
{
public:
  int countServers(vector<vector<int>> &grid)
  {
    int m = grid.size();    // Number of rows in the grid
    int n = grid[0].size(); // Number of columns in the grid

    // Arrays to store the count of servers in each row and column
    vector<int> indexColCount(n, 0);
    vector<int> indexRowCount(m, 0);

    // Preprocessing: Count servers in each row and column
    for (int row = 0; row < m; row++)
    {
      for (int col = 0; col < n; col++)
      {
        if (grid[row][col] == 1)
        {                          // Found a server at grid[row][col]
          indexColCount[col] += 1; // Increment count for the column
          indexRowCount[row] += 1; // Increment count for the row
        }
      }
    }

    int resultServers = 0; // Counter for servers that can communicate

    // Traverse the grid again to find servers that can communicate
    for (int row = 0; row < m; row++)
    {
      for (int col = 0; col < n; col++)
      {
        // A server can communicate if there are more than 1 server
        // in its row or column
        if (grid[row][col] == 1 && (indexColCount[col] > 1 || indexRowCount[row] > 1))
        {
          resultServers++;
        }
      }
    }

    // Return the total count of servers that can communicate
    return resultServers;
  }
};

/*
 * Approach - 3 (Another Better Approach using Row and Column Server Tracking)
 * -------------------------------------------------------------------------
 * In this approach, we track servers in each row and column. We use an array
 * to count servers in each column and another to mark servers that are
 * the only server in their row. This allows us to handle row and column
 * communication in a more efficient manner.
 *
 * Time Complexity: O(m * n)
 * - We traverse the grid twice: first to count servers in rows and columns,
 *   and then to check for isolated servers.
 *
 * Space Complexity: O(m + n)
 * - We use arrays to store the server counts for each row and column.
 */

class Solution
{
public:
  int countServers(vector<vector<int>> &grid)
  {
    int m = grid.size();    // Number of rows in the grid
    int n = grid[0].size(); // Number of columns in the grid

    // Arrays to store the count of servers in each column and mark row isolation
    vector<int> colServerCount(n, 0);
    vector<int> RowAkelaServerCol(m, -1);

    int resultServers = 0; // Counter for servers that can communicate

    // Traverse the grid to count servers in each row and column
    for (int row = 0; row < m; row++)
    {
      int countServersRow = 0; // Count servers in the current row
      for (int col = 0; col < n; col++)
      {
        if (grid[row][col] == 1)
        {                               // Found a server at grid[row][col]
          countServersRow += 1;         // Increment row server count
          colServerCount[col]++;        // Increment column server count
          RowAkelaServerCol[row] = col; // Mark the column if this is the last server in the row
        }
      }

      // If there are more than 1 server in the row, they can communicate
      if (countServersRow > 1)
      {
        resultServers += countServersRow; // Add all servers in this row
        RowAkelaServerCol[row] = -1;      // Mark as no isolated server in this row
      }
    }

    // Check for isolated servers in rows
    for (int row = 0; row < m; row++)
    {
      if (RowAkelaServerCol[row] != -1)
      { // There is a single server in this row
        int col = RowAkelaServerCol[row];
        // If there’s more than 1 server in the same column, the server can communicate
        if (colServerCount[col] > 1)
        {
          resultServers += 1; // Increment result for the isolated server that can communicate
        }
      }
    }

    return resultServers; // Return the total count of servers that can communicate
  }
};
