#include <bits/stdc++.h>
using namespace std;

// Approach-3 (Optimal - using a 2-d substring store)
// T.C : O(n)
// S.C : O(26*n) ~ O(n)
class Solution
{
public:
  int maximumLength(string s)
  {
    // Length of String
    int n = s.length();

    // Create a 2D matrix to store the frequency of substring lengths for each character.
    // matrix[i][j] represents the frequency of substrings of length j for character 'a' + i.
    vector<vector<int>> matrix(26, vector<int>(n + 1, 0));

    // Track the previous character to detect consecutive repetitions.
    char prev_char = s[0];

    // Length of the current substring of repeated characters.
    int length = 0;

    // Iterate through the string to populate the 2D matrix.
    for (int i = 0; i < n; i++)
    {
      char curr_char = s[i];

      if (curr_char == prev_char)
      {
        // If the current character matches the previous, extend the current substring length.
        length += 1;
        // Increment the frequency for this length.
        matrix[curr_char - 'a'][length] += 1;
      }
      else
      {
        // If a different character is encountered, reset the length to 1.
        length = 1;
        matrix[curr_char - 'a'][length] += 1;

        // Update the previous character.
        prev_char = curr_char;
      }
    }

    // Variable to store the maximum valid substring length.
    int result = 0;

    // Process the 2D matrix to calculate the result.
    for (int i = 0; i < 26; i++) // O(26)
    {
      // Cumulative sum of substring frequencies for a specific character.
      int cumSum = 0;

      for (int j = n; j >= 1; j--) // O(N)
      {
        // Add the frequency of substrings of length j.
        cumSum += matrix[i][j];

        // Check if at least 3 substrings of length j exist.
        if (cumSum >= 3)
        {
          // Update the result with the maximum length.
          result = max(result, j);
          break; // No need to check smaller lengths for this character.
        }
      }
    }

    // If no valid substring is found, return -1. Otherwise, return the result.
    return result == 0 ? -1 : result;
  }
};
