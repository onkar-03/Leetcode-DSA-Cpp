#include <bits/stdc++.h>
using namespace std;

// Approach-1: Brute Force - Check All Rotations
// Time Complexity: O(n^2), where n is the length of the string.
// Space Complexity: O(1), as we're only modifying the string in place.

class Solution
{
public:
  bool rotateString(string s, string goal)
  {
    // Store the lengths of both strings for easy comparison
    int m = s.length();
    int n = goal.length();

    // If the lengths are not equal, they can't be rotations of each other
    if (m != n)
      return false;

    // Try all possible rotations of string `s`
    for (int rotationCount = 1; rotationCount <= m; ++rotationCount)
    {
      // Perform one rotation by shifting the string `s` to the left by one position
      // rotate() takes 3 arguments: 1. Start Position 2.Which one would be the new Start 3. End Position
      // `rotate` moves the character at `s.begin() + 1` to `s.begin()` and shifts the rest of the characters to the left accordingly.
      rotate(s.begin(), s.begin() + 1, s.end());

      // After rotation, check if `s` matches `goal`
      if (s == goal)
        return true; // If they match, return true as we found a valid rotation
    }

    // If no rotation of `s` matches `goal`, return false
    return false;
  }
};
