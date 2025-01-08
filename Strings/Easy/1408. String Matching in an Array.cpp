#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// Time Complexity (T.C): O(m * n^2)
// - m = length of the longest string in the words vector.
// - n = size of the words vector.
// The .find() function takes O(m) time to check for a substring match,
// and the nested loop contributes an O(n^2) factor, resulting in O(m * n^2) overall.

// Space Complexity (S.C): O(1)
// - No additional data structures are used apart from the result vector.
class Solution
{
public:
  vector<string> stringMatching(vector<string> &words)
  {
    // Get the total number of words in the vector.
    int n = words.size();

    // Vector to store the strings that are substrings of other strings.
    vector<string> result;

    // Iterate through each word in the words vector.
    for (int i = 0; i < n; i++)
    {
      // Compare the current word with all other words.
      for (int j = 0; j < n; j++)
      {
        // Skip comparison with itself (a word cannot be a substring of itself).
        if (i == j)
        {
          continue;
        }

        // Check if words[j] is a substring of words[i] using .find()
        // If its not a substring then string::npos is returned
        if (words[i].find(words[j]) != string::npos)
        {
          // If a match is found, add words[i] to the result and break out of the inner loop.
          result.push_back(words[i]);
          break; // No need to check further for the current word.
        }
      }
    }
    // Return the result vector containing all substring matches.
    return result;
  }
};

// Approach-2 (Using KMP Algorithm)
// T.C: O(m * n^2), where m = length of the longest string in words, n = size of words
// S.C: O(m), space used for the LPS array
class Solution
{
public:
  void computeLPS(string pattern, vector<int> &lps)
  {
    int M = pattern.length();
    int len = 0; // Length of the previous longest prefix which is also a suffix

    lps[0] = 0; // No proper prefix for the first character

    int i = 1; // Start calculating LPS from the second character
    while (i < M)
    {
      if (pattern[i] == pattern[len])
      {
        // Characters match, so we extend the current prefix
        len++;
        lps[i] = len;
        i++;
      }
      // Characters do not match
      else
      {
        // If length is still not 0
        if (len != 0)
        {
          // Move to the last known longest prefix length
          len = lps[len - 1];
        }
        else
        {
          // No prefix matches, set LPS[i] to 0
          lps[i] = 0;
          i++;
        }
      }
    }
  }

  bool searchKMP(string pat, string txt)
  {
    int N = txt.length();
    int M = pat.length();

    // Create the LPS array for the pattern
    vector<int> lps(M, 0);
    computeLPS(pat, lps);

    int i = 0; // Pointer for text
    int j = 0; // Pointer for pattern

    while (i < N)
    {
      // CHaracters Match
      if (pat[j] == txt[i])
      {
        // As characters match, move both pointers forward
        i++;
        j++;
      }

      // Full pattern found in the text
      if (j == M)
      {
        return true;
      }

      // Characters do not match
      else if (i < N && pat[j] != txt[i])
      {
        // Only is j is not zero we assign value to j of its previous index
        if (j != 0)
        {
          // Move the pattern pointer back using the LPS array
          j = lps[j - 1];
        }
        else
        {
          // If no prefix match, move the text pointer forward
          i++;
        }
      }
    }

    return false; // Pattern not found
  }

  vector<string> stringMatching(vector<string> &words)
  {
    int n = words.size();
    vector<string> result;

    // Compare each word with every other word in the list
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (i == j)
          continue; // Skip comparing the word with itself

        // Check if `words[i]` is a substring of `words[j]` using KMP
        if (searchKMP(words[i], words[j]))
        {
          result.push_back(words[i]);
          break; // Once found, move to the next word
        }
      }
    }

    return result; // Return the list of matching substrings
  }
};
