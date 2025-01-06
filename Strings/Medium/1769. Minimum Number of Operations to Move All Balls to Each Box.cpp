#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force Using unordered_set for extra space)
// Time Complexity: O(n^2) - For each box, we iterate through the indices of boxes containing '1'.
// Space Complexity: O(n) - For storing indices of boxes with '1' in the unordered_set.
class Solution
{
public:
  vector<int> minOperations(string boxes)
  {
    int n = boxes.length();
    unordered_set<int> st; // To store indices of boxes containing '1'.

    // Step 1: Populate the unordered_set with indices of boxes that contain '1'.
    for (int i = 0; i < n; i++)
    {
      if (boxes[i] == '1')
      {
        st.insert(i);
      }
    }

    vector<int> answer(n, 0); // Initialize the result array with 0.

    // Step 2: For each box, calculate the total number of operations
    // needed to move all '1's to that box.
    for (int i = 0; i < n; i++)
    {
      for (auto &idx : st)
      {
        answer[i] += abs(i - idx); // Add the distance between the current index and the '1' indices.
      }
    }

    return answer; // Return the result array containing the minimum operations for each box.
  }
};
