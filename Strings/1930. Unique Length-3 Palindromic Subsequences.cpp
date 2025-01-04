#include <bits/stdc++.h>
using namespace std;

// Approach - 1
// Time Complexity: O(n)
// Space Complexity: O(1) - The unordered_set to store unique letters will always hold at most 26 characters (for lowercase English letters).

class Solution
{
public:
  int countPalindromicSubsequence(string s)
  {
    int n = s.length();

    // Step 1: Find all unique characters in the string.
    unordered_set<char> unique_letters;
    for (char &ch : s)
    {
      unique_letters.insert(ch);
    }

    int result = 0;

    // Step 2: Process each unique character as the potential "first" and "last" character of a palindrome.
    for (char letter : unique_letters)
    {
      int first_idx = -1; // Index of the first occurrence of the character.
      int last_idx = -1;  // Index of the last occurrence of the character.

      // Find the first and last occurrence of the character.
      for (int i = 0; i < n; i++)
      {
        if (s[i] == letter)
        {
          if (first_idx == -1)
          {
            first_idx = i; // Update first occurrence.
          }
          last_idx = i; // Update last occurrence.
        }
      }

      // If the character appears more than once, collect characters between its first and last occurrence.
      unordered_set<char> st; // Stores unique characters between first_idx and last_idx.
      for (int middle = first_idx + 1; middle <= last_idx - 1; middle++)
      {
        st.insert(s[middle]);
      }

      // Add the count of unique middle characters to the result.
      result += st.size();
    }

    return result; // Return the total count of unique palindromic subsequences.
  }
};
