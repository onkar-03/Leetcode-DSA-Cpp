#include <bits/stdc++.h>
using namespace std;

// Approach-1: Brute Force usign .find()
// Time Complexity: O(n * m), where n = number of words in the vector and m = length of the prefix string `pref`.
// Space Complexity: O(1), as no extra space is used apart from variables.
class Solution
{
public:
  int prefixCount(vector<string> &words, string pref)
  {
    int count = 0; // Initialize a counter to store the number of words that match the prefix.

    // Iterate through each word in the vector `words`.
    for (string &word : words)
    {
      // Check if the current word starts with the prefix `pref`.
      // `word.find(pref) == 0` means the prefix matches the start of the word.
      if (word.find(pref) == 0)
      {
        count++; // Increment the counter if the prefix matches.
      }
    }

    // Return the total count of words that start with the prefix `pref`.
    return count;
  }
};
