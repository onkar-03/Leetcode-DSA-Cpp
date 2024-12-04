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
      // Check if the current character of str1 can match the current character of str2
      if (
          // Condition 1: The characters are exactly the same
          (str1[i] == str2[j]) ||

          // Condition 2: The character in str1 can be incremented by 1 to match the character in str2
          // For example, 'a' in str1 can become 'b' in str2
          (str1[i] + 1 == str2[j]) ||

          // Condition 3: Handle wrap-around cases, where 'z' in str1 wraps around to match 'a' in str2
          // This ensures cyclic behavior in the character matching
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
