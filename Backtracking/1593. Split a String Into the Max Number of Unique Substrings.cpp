#include <bits/stdc++.h>
using namespace std;

// Approach (Using simple backtracking)
// Backtracking: 1. Do, 2. Explore, 3.Undo
// T.C : O(n^2 * 2^n)
// S.C : O(n)
class Solution
{
public:
  // A helper function that uses backtracking to find the maximum number of unique substrings.
  // s: the input string
  // idx: the current index in the string being processed
  // st: an unordered_set to store the unique substrings encountered so far
  // currCount: the current number of unique substrings found
  // maxCount: the maximum number of unique substrings encountered so far taken using & as we want it to reflect in original value
  void solve(string &s, int idx, unordered_set<string> &st, int currCount, int &maxCount)
  {

    // Pruning:
    // It refers to eliminating unnecessary computations and reduce the search space.
    // If the current count plus the remaining part of the string (s.length() - idx), cannot exceed maxCount, terminate the search early for efficiency.
    if (currCount + (s.length() - idx) <= maxCount)
    {
      return;
    }

    // If we have processed the entire string, update maxCount with the current count if it's larger.
    if (idx == s.length())
    {
      // Make sure to return here as the string is fully processed
      maxCount = max(maxCount, currCount);
      return;
    }

    // Loop to explore all possible substrings starting from the current index.
    for (int j = idx; j < s.length(); j++)
    {
      // 1. Do
      // Extract the substring from the current index 'idx' to 'j' (inclusive).
      string sub = s.substr(idx, j - idx + 1); // O(N)

      // If this substring is not already in the set (i.e., it is unique), process further.
      if (st.find(sub) == st.end())
      {
        // Insert this new substring into the set of unique substrings.
        st.insert(sub);

        // 2. Explore
        // Recursively call the solve function, moving the starting index to j+1 (the next character) and incrementing the current count of unique substrings.
        solve(s, j + 1, st, currCount + 1, maxCount);

        // 3. Undo
        // Backtrack: remove the current substring from the set to explore other possibilities.
        st.erase(sub);
      }
    }
  }

  // The main function that initiates the process of finding the maximum number of unique substrings.
  int maxUniqueSplit(string s)
  {
    // Create a set to track unique substrings.
    unordered_set<string> st;

    // Variables to store the maximum and current count of unique substrings.
    int maxCount = 0;
    int currCount = 0;

    // Call the solve function starting from index 0.
    solve(s, 0, st, currCount, maxCount);

    // Return the maximum count of unique substrings.
    return maxCount;
  }
};
