#include <bits/stdc++.h>
using namespace std;

// Approach: Simple traversal using two pointers
// Time Complexity: O(m + n), where m and n are the lengths of str1 and str2 respectively.
// Space Complexity: O(1), as we use constant extra space.
class Solution
{
public:
  bool canMakeSubsequence(string str1, string str2)
  {
    // Get lengths of both strings
    int m = str1.length();
    int n = str2.length();

    // If str2 is longer than str1, it's impossible to form str2 as a subsequence
    if (n > m)
    {
      return false;
    }

    // Initialize two pointers for str1 (i) and str2 (j)
    int i = 0;
    int j = 0;

    // Traverse both strings
    while (i < m && j < n)
    {
      // Check if the current character of str1 matches the current character of str2,
      // or can be incremented by 1 to match, or wraps around (e.g., 'z' -> 'a').
      if ((str1[i] == str2[j]) ||
          (str1[i] + 1 == str2[j]) ||
          (str1[i] - 25 == str2[j]))
      {
        // Move pointer j to the next character in str2
        j++;
      }
      // Always move pointer i to the next character in str1
      i++;
    }

    // If we've matched all characters in str2, return true; otherwise, return false
    return j == n;
  }
};
