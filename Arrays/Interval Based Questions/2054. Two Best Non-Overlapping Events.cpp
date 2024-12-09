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

// Approach-2 (Recursion + Memoization and Sorting)
// T.C : O(n * logn) - Sorting takes O(n * logn), and with memoization, we visit at most n states, where each state involves a binary search (O(logn)).
// S.C : O(n*3) ~= O(n) - Space used for memoization table and recursion stack.
class Solution
{
public:
  // Total number of events
  int n;

  // Memoization table: t[i][count] stores the max value starting from event i with `count` events taken
  // 100001 coz we have max value as 10^5
  // 3 as max count we can pick is 2
  int t[100001][3];

  // Returns the index of the first event starting after `endTime`
  // Performs 'upper_bound' of EndTime of Current Event
  int binarySearch(vector<vector<int>> &events, int endTime)
  {
    int l = 0, r = n - 1;
    int result = n; // Default to n (no valid event found)

    while (l <= r)
    {
      int mid = l + (r - l) / 2; // Midpoint calculation to avoid overflow

      // If we get a valid Start thats after the ending of the current event then we store it and look for any further events to the left of the mid that fulfill the same condition
      if (events[mid][0] > endTime)
      {
        result = mid; // Potential valid event
        r = mid - 1;  // Narrow search to the left
      }

      // Otherwise as the start is still lesser than the end the current event list that's already sorted then we move to further greater values of start position i.e to the right of mid
      else
      {
        l = mid + 1; // Narrow search to the right
      }
    }

    return result;
  }

  // Recursive function to calculate the maximum value of at most two events
  int solve(vector<vector<int>> &events, int i, int count)
  {
    // Base case: Stop if we have selected 2 events or there are no more events
    if (count == 2 || i >= n)
    {
      return 0;
    }

    // Check if the result for this state is already computed
    if (t[i][count] != -1)
    {
      return t[i][count];
    }

    // Find the next valid starting index of event thats greater than the ending after the current event
    int nextValidEventIndex = binarySearch(events, events[i][1]);

    // Option 1: Take the current event and proceed to the next valid event
    int take = events[i][2] + solve(events, nextValidEventIndex, count + 1);

    // Option 2: Skip the current event and proceed to the next event
    int not_take = solve(events, i + 1, count);

    // Store and return the maximum of the two options
    return t[i][count] = max(take, not_take);
  }

  // Main function to calculate the maximum value of two non-overlapping events
  int maxTwoEvents(vector<vector<int>> &events)
  {
    n = events.size();                // Get the total number of events
    sort(begin(events), end(events)); // Sort events by start time for binary search
    memset(t, -1, sizeof(t));         // Initialize memoization table with -1

    int count = 0;                  // Initialize event count
    return solve(events, 0, count); // Start solving from the first event
  }
};
