#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force - Try all possible substrings)
// T.C : O(n^3), when we iterate and map each substring in the map
// S.C : O(n^2), total substrings in worst case for n length string is N^2
class Solution
{
public:
  int maximumLength(string s)
  {
    // Get the length of the input string
    int n = s.length();

    // A map to store substrings and their occurrence counts
    map<string, int> mp;

    // Iterate through the string to generate substrings of contiguous identical characters
    for (int i = 0; i < n; i++) // O(N)
    {
      // Initialize an empty string to build the substring
      string curr;

      // Iterate over the Current String to build all possible substrings
      for (int j = i; j < n; j++) // O(N)
      {
        // If the current character matches the last character of `curr` (or `curr` is empty), add the character to `curr`
        if (curr.empty() || curr.back() == s[j])
        {
          // Add the character to the substring.
          curr.push_back(s[j]);

          // Increment the count of this substring in the map
          // To copy the string and increment the count in map the time taken is O(N)
          mp[curr]++;
        }
        // Stop extending the substring if the current character doesn't match
        else
        {
          break;
        }
      }
    }

    // Initialize the result variable to store the maximum valid substring length
    int result = 0;

    // Iterate through the map to find substrings that occur at least 3 times
    for (auto &it : mp)
    {
      string str = it.first; // Get the substring
      int count = it.second; // Get its occurrence count

      // If the substring occurs at least 3 times and is longer than the current result
      if (count >= 3 && str.length() > result)
      {
        // Update the result with the length of this substring
        result = str.length();
      }
    }

    // If no valid substring is found, return -1. Otherwise, return the maximum length found
    return result == 0 ? -1 : result;
  }
};

// Approach-2 (Better Brute Force)
// T.C : O(n^2), only for when we iterate over the string to get all possible substrings
// S.C : O(n^2)
class Solution
{
public:
  int maximumLength(string s)
  {
    int n = s.length(); // Get the length of the input string

    // A map to store pairs of (character, substring length) as keys and their occurrence count as values
    // Also we cant use unordered map to store Pair in it hence we use ordered map / map
    map<pair<char, int>, int> mp;

    // Loop through the string to calculate substrings with contiguous identical characters
    for (int i = 0; i < n; i++) // O(N)
    {
      char ch = s[i]; // Current character
      int l = 0;      // Length of the current contiguous substring

      // Extend the substring while the characters are the same
      for (int j = i; j < n; j++) // O(N)
      {
        if (s[j] == ch)
        {
          // Increase the length of the current substring
          l++;
          // Update the map with the character and length
          // Also the saving of char length and its value of occurrence not is done in O(1) Time
          mp[{ch, l}]++;
        }
        else
        {
          break; // Stop when a different character is encountered
        }
      }
    }

    int result = 0; // Initialize the result to store the maximum valid substring length

    // Iterate through the map to find the maximum length of substrings that appear at least 3 times
    for (auto &it : mp)
    {
      // Extract the length of the substring and its frequency from the map
      char ch = it.first.first;     // Character to extract
      int length = it.first.second; // Substring length.
      int freq = it.second;         // Frequency of the substring.

      // Check if the substring appears at least 3 times and has the longest length so far
      if (freq >= 3 && length > result)
      {
        // Update the result
        result = length;
      }
    }

    // If no valid substring is found, return -1. Otherwise, return the maximum length
    return result == 0 ? -1 : result;
  }
};
