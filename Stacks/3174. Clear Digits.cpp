#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// T.C : O(n^2)
//  - In the worst case, each digit removal causes a shift of O(n), leading to O(n^2) complexity.
// S.C : O(1)
//  - We modify the input string in place without extra space.
class Solution
{
public:
  string clearDigits(string s)
  {
    int i = 0; // Initialize index pointer

    // Iterate through the string
    while (i < s.size())
    {
      if (isdigit(s[i]))
      { // Check if the character is a digit

        s.erase(i, 1); // Remove the digit
        if (i > 0)
        {
          s.erase(i - 1, 1); // Remove the preceding character
          i--;               // Adjust index to avoid skipping characters
        }
      }
      else
      {
        i++; // Move to the next character
      }
    }
    return s; // Return the modified string
  }
};
