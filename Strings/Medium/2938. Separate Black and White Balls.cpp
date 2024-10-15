
#include <bits/stdc++.h>
using namespace std;

// Approach-1 (straightforward traversal)
// T.C : O(n) - Time Complexity is linear since we traverse the string once
// S.C : O(1) - Space Complexity is constant since we use a fixed amount of space

class Solution
{
public:
  // Function to calculate the minimum steps needed to sort the string
  long long minimumSteps(string s)
  {
    // Get the length of the input string
    int n = s.length();

    // Initialize swap counter to keep track of the number of swaps needed
    long long swap = 0;

    // Initialize counter for the number of '1's (black)
    int black = 0;

    // Iterate through each character in the string
    for (int i = 0; i < n; i++)
    {
      // Check if the current character is '0' (white)
      if (s[i] == '0')
      {
        // If it's a '0', we need to move it to the left
        // The number of swaps needed is equal to the number of '1's
        // (blacks) encountered so far, as each '1' will need to move past this '0'
        swap += black;
      }
      else
      {
        // If it's a '1', increment the count of '1's (blacks)
        // since we have seen one more '1' in the string
        black++;
      }
    }

    // Return the total number of swaps needed to arrange the '0's to the left
    // and '1's to the right
    return swap;
  }
};
