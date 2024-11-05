#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Simple iterate and count and keep track)
// T.C : O(n) - Linear time complexity as we iterate through the string once
// S.C : O(1) - Constant space complexity as we use a fixed amount of extra space
class Solution
{
public:
  int minChanges(string s)
  {
    char curr = s[0];   // Initialize `curr` with the first character of the string
    int count = 0;      // Initialize `count` to keep track of consecutive characters
    int changes = 0;    // Initialize `changes` to count the minimum changes needed
    int n = s.length(); // Store the length of the string for easy access

    // Iterate through each character in the string
    for (int i = 0; i < n; i++)
    {
      if (s[i] == curr)
      {           // Check if the current character is the same as `curr`
        count++;  // Increment the `count` of consecutive same characters
        continue; // Continue to the next iteration if the character is the same
      }

      // If we encounter a different character, check the `count`
      if (count % 2 == 0)
      { // If `count` is even, reset `count` to 1
        count = 1;
      }
      else
      {            // If `count` is odd, reset `count` and increase `changes`
        count = 0; // Reset `count` to 0 as we need an adjustment
        changes++; // Increment `changes` to count the necessary change
      }

      curr = s[i]; // Update `curr` to the new character
    }

    return changes; // Return the minimum changes needed
  }
};

// Approach-2 (Simple iterate and count and keep track)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
  int minChanges(string s)
  {
    // Initialize a counter to track the required changes
    int changes = 0;
    // Get the length of the input string
    int n = s.length();

    // Iterate through the string, incrementing by 2 each time to check each consecutive pair (s[i], s[i+1])
    for (int i = 0; i < n; i += 2)
    {
      // Check if the current character differs from the next character
      if (s[i] != s[i + 1])
      {
        // If they differ, increment the change counter
        changes++;
      }
    }

    // Return the total number of changes required
    return changes;
  }
};
