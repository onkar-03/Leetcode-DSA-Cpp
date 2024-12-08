#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force) - TLE (Time Limit Exceeded)
// T.C : O(n^2) - Quadratic time complexity due to nested loops
// S.C : O(1) - Constant space complexity, as no additional data structures are used
class Solution
{
public:
  int maxTwoEvents(vector<vector<int>> &events)
  {
    int n = events.size(); // Number of events
    int result = 0;        // Initialize the maximum value to 0

    // Outer loop: Iterate over each event as the first event to consider
    for (int i = 0; i < n; i++)
    {
      // Update the result considering only the current event's value
      result = max(result, events[i][2]);

      int val = events[i][2]; // Value of the current event

      // Inner loop: Compare the current event with all other events
      for (int j = 0; j < n; j++)
      {
        // Skip if both indices are the same (same event)
        if (i == j)
        {
          continue;
        }

        // Check for overlapping events
        // If the start or end times of event[j] overlap with event[i], skip
        if (events[j][0] <= events[i][1] && events[j][1] >= events[i][0])
        {
          continue;
        }

        // Update the result considering the sum of non-overlapping events
        result = max(result, val + events[j][2]);
      }
    }

    return result; // Return the maximum value of two non-overlapping events
  }
};
