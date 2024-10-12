#include <bits/stdc++.h>
using namespace std;

// Approach: Simply sorting the intervals and using a min-heap (priority queue)
// Time Complexity: O(n log n) - due to sorting the intervals
// Space Complexity: O(n) - for the priority queue to store end points

class Solution
{
public:
  int minGroups(vector<vector<int>> &intervals)
  {
    // Step 1: Sort the intervals based on their starting point.
    // This ensures that we process them in order.
    sort(begin(intervals), end(intervals));

    // Step 2: Create a min-heap (priority queue) to keep track of the end points of the intervals.
    // This will help us efficiently manage overlapping intervals.
    priority_queue<int, vector<int>, greater<int>> pq; // Stores end points of groups

    // Step 3: Iterate through each interval in the sorted list.
    for (vector<int> &interval : intervals)
    {
      int start = interval[0]; // Extract the starting point of the current interval
      int end = interval[1];   // Extract the ending point of the current interval

      // Step 4: Check if the min-heap is not empty and if the smallest end point in the heap is less than the start of the current interval.
      // If this condition is true, it means the current interval does not overlap with the group represented by the smallest end point.
      if (!pq.empty() && pq.top() < start)
      {
        // Step 5: Remove the group from the heap since the current interval can start a new group.
        pq.pop();
      }

      // Step 6: Add the current interval's end point to the min-heap.
      // This effectively creates or updates the group for the current interval.
      pq.push(end);
    }

    // Step 7: The size of the min-heap at the end will give us the minimum number of groups required.
    return pq.size();
  }
};
