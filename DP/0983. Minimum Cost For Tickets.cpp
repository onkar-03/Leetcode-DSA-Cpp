#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Recursion + Memoization)
// Time Complexity: O(max_day) - At most, we compute for each day only once due to memoization.
// Space Complexity: O(n) - Due to recursion stack and memoization array (t), where n = size of the `days` vector.
class Solution
{
public:
  int t[366]; // Memoization table to store results for each index (max size = 365 days + 1).

  // Helper function to calculate the minimum cost using recursion and memoization.
  int memoized(vector<int> &days, vector<int> &costs, int &n, int idx)
  {
    // Base case: If the index is out of bounds, no cost is needed.
    if (idx >= n)
      return 0;

    // If the result is already computed for this index, return it.
    if (t[idx] != -1)
      return t[idx];

    // Case 1: Taking a 1-day pass starting from the current day.
    int cost_1 = costs[0] + memoized(days, costs, n, idx + 1);

    // Case 2: Taking a 7-day pass starting from the current day.
    // Move the index `i` to the first day outside the 7-day window.
    int i = idx;
    while (i < n && days[i] < days[idx] + 7)
    {
      i++;
    }
    int cost_7 = costs[1] + memoized(days, costs, n, i);

    // Case 3: Taking a 30-day pass starting from the current day.
    // Move the index `j` to the first day outside the 30-day window.
    int j = idx;
    while (j < n && days[j] < days[idx] + 30)
    {
      j++;
    }
    int cost_30 = costs[2] + memoized(days, costs, n, j);

    // Store the minimum cost among the three options in the memoization table and return it.
    return t[idx] = min({cost_1, cost_7, cost_30});
  }

  // Main function to calculate the minimum cost of tickets.
  int mincostTickets(vector<int> &days, vector<int> &costs)
  {
    // Initialize the memoization table with -1 to signify uncomputed states.
    memset(t, -1, sizeof(t));
    int n = days.size(); // Get the number of travel days.
    // Start the recursion from the first day (index 0).
    return memoized(days, costs, n, 0);
  }
};
