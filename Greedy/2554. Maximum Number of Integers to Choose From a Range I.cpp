#include <bits/stdc++.h>
using namespace std;

// Approach: Greedy Selection of Smallest Numbers
// Time Complexity: O(n)
// - We iterate through numbers from 1 to n once.
// Space Complexity: O(m)
// - m is the size of the `banned` list, which is stored in an unordered_set for O(1) lookups.

class Solution
{
public:
  int maxCount(vector<int> &banned, int n, int maxSum)
  {
    // Create a set from the banned list for quick lookup, as we can lookup usign O(1) time in Set whereas in vector<int> banned it would take O(N) time
    unordered_set<int> st(begin(banned), end(banned));

    int count = 0; // Counter for selected numbers
    int sum = 0;   // Accumulator for the current sum of selected numbers

    // Iterate over numbers from 1 to n
    for (int num = 1; num <= n; num++)
    {
      // Skip the number if it is banned
      if (st.count(num))
      {
        continue;
      }

      // Check if adding the current number exceeds maxSum
      if (sum + num <= maxSum)
      {
        count++;    // Increment the count of valid numbers
        sum += num; // Add the number to the sum
      }
      else
      {
        break; // Stop if the sum exceeds maxSum
      }
    }

    return count; // Return the maximum count of numbers
  }
};
