#include <bits/stdc++.h>
using namespace std;

// Approach: Simple Traversal
// T.C: O(n)
// S.C: O(1)
class Solution
{
public:
  // Function to make a "fancy" string by removing extra consecutive characters
  string makeFancyString(string s)
  {
    string ans = "";            // Initialize an empty string to store the result
    ans.push_back(s[0]);        // Add the first character of input string to the result
    int n = s.size(), freq = 1; // Store the size of the input string and initialize frequency counter

    // Traverse the string from the second character to the end
    for (int i = 1; i < n; i++)
    {
      // Check if the current character is the same as the last character in the result
      if (s[i] == ans.back())
      {
        freq++; // Increment frequency counter
        // Only add the character if frequency is less than 3
        if (freq < 3)
        {
          ans.push_back(s[i]);
        }
      }
      else
      {
        // If the current character is different, reset frequency to 1
        freq = 1;
        // Add the new character to the result
        ans.push_back(s[i]);
      }
    }

    return ans; // Return the "fancy" string with no more than two consecutive identical characters
  }
};
