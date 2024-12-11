#include <bits/stdc++.h>
using namespace std;
// Approach-1: Convert the problem into intervals and find the maximum overlapping intervals.
// Time Complexity: O(n log n) - Due to sorting of ranges.
// Space Complexity: O(n) - For storing intervals and the deque.
class Solution
{
public:
  int maximumBeauty(vector<int> &nums, int k)
  {
    // Step 1: Convert each number into an interval [num - k, num + k]
    // This represents the range of values that can contribute to "beauty".
    vector<pair<int, int>> ranges;
    for (int num : nums)
    {
      ranges.push_back({num - k, num + k});
    }

    // Step 2: Sort the intervals by their start points.
    // Sorting helps in processing intervals in order, allowing us to efficiently track overlaps.
    sort(ranges.begin(), ranges.end());

    int maxBeauty = 0; // Variable to track the maximum "beauty" value.
    deque<int> deq;    // Deque to store the end points of overlapping intervals.

    // Step 3: Traverse through each interval in the sorted list.
    for (const auto &range : ranges)
    {
      // Remove intervals from the deque that no longer overlap with the current interval.
      // Since the deque is sorted by range endpoints, we only check the front.
      while (!deq.empty() && deq.front() < range.first)
      {
        deq.pop_front();
      }

      // Add the endpoint of the current interval to the deque.
      deq.push_back(range.second);

      // The size of the deque now represents the count of overlapping intervals,
      // which is equivalent to the current "beauty" value.
      maxBeauty = max(maxBeauty, (int)deq.size());
    }

    return maxBeauty; // Return the maximum beauty found.
  }
};
