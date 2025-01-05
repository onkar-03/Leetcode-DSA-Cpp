#include <bits/stdc++.h>
using namespace std;

// Approach: Using Difference Array Technique
// Time Complexity: O(m + n), where m = number of queries, n = length of the string
// Space Complexity: O(n), for the difference array
class Solution
{
public:
  string shiftingLetters(string s, vector<vector<int>> &shifts)
  {
    int n = s.size();       // Length of the input string
    vector<int> diff(n, 0); // Difference array to track the net effect of shifts

    // Step 1: Populate the difference array using the shift queries
    for (const auto &shift : shifts)
    {
      int start = shift[0];     // Starting index of the shift
      int end = shift[1];       // Ending index of the shift
      int direction = shift[2]; // Direction of the shift: 1 = forward, 0 = backward

      if (direction == 1)
      {                   // Forward shift
        diff[start] += 1; // Increment at the starting index
        if (end + 1 < n)  // Decrement after the ending index (to mark the end of the range)
          diff[end + 1] -= 1;
      }
      else
      {                   // Backward shift
        diff[start] -= 1; // Decrement at the starting index
        if (end + 1 < n)  // Increment after the ending index
          diff[end + 1] += 1;
      }
    }

    // Step 2: Compute the prefix sum to get the net shifts for each character
    for (int i = 1; i < n; ++i)
    {
      diff[i] += diff[i - 1]; // Add the value of the previous index to compute the cumulative effect
    }

    // Step 3: Apply the calculated shifts to the string
    for (int i = 0; i < n; ++i)
    {
      int shift = diff[i] % 26; // Reduce the shift to fit within the range [0, 25]
      if (shift < 0)
        shift += 26; // Handle negative shifts (convert to equivalent positive shift)

      // Apply the calculated shift to the current character
      s[i] = ((s[i] - 'a' + shift) % 26) + 'a';
      /*
          Explanation:
          1. s[i] - 'a': Converts the character to its 0-based position (0 = 'a', 1 = 'b', ..., 25 = 'z').
          2. + shift: Adds the net shift value.
          3. % 26: Wraps around to ensure the position is within [0, 25].
          4. + 'a': Converts the 0-based position back to a character.
      */
    }

    return s; // Return the final shifted string
  }
};
