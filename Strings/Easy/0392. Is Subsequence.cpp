#include <bits/stdc++.h>
using namespace std;

// Approach: Two-Pointer Technique
// Time Complexity: O(n), where n is the length of the string `t`.
// Space Complexity: O(1), as no extra space is used.
class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    // Get the lengths of both strings
    int m = s.length();
    int n = t.length();

    // Initialize two pointers:
    // i -> points to characters in string `s`
    // j -> points to characters in string `t`
    int i = 0, j = 0;

    // Traverse both strings using the two pointers
    while (i < m && j < n)
    {
      // If the current character of `s` matches the current character of `t`
      if (s[i] == t[j])
      {
        // Move pointer `i` to the next character in `s`
        i++;
      }
      // Always move pointer `j` to the next character in `t`
      j++;
    }

    // After traversal, check if we have matched all characters of `s`
    return i == m;
  }
};
