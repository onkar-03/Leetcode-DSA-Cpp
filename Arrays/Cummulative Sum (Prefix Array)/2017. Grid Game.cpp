#include <bits/stdc++.h>
using namespace std;

// Approach - (Using Cumulative Sum & Game Strategy)
// T.C : O(col), col = total columns in the grid
// S.C : O(1)
class Solution
{
public:
  long long gridGame(vector<vector<int>> &grid)
  {
    // Calculate the total sum of the first row as the initial remaining score for Robot 1
    long long firstRowRemaining = accumulate(grid[0].begin(), grid[0].end(), 0LL);

    // Initialize the sum of elements Robot 2 has collected so far
    long long secondRowRemaining = 0;

    // Variable to track the minimum possible maximum score Robot 2 can achieve
    long long minimizedRobot2 = LONG_LONG_MAX;

    // Iterate through each column where Robot 1 chooses to turn downward
    for (int robot1 = 0; robot1 < grid[0].size(); robot1++)
    {
      // Subtract the current column value from Robot 1's remaining score
      firstRowRemaining -= grid[0][robot1];

      // Calculate the maximum score Robot 2 could achieve after Robot 1's turn
      long long bestOfRobot2 = max(firstRowRemaining, secondRowRemaining);

      // Update the minimum score Robot 2 could be forced to achieve
      minimizedRobot2 = min(bestOfRobot2, minimizedRobot2);

      // Add the current column value to Robot 2's collected score
      secondRowRemaining += grid[1][robot1];
    }
    // Return the minimized maximum score Robot 2 can achieve
    return minimizedRobot2;
  }
};
