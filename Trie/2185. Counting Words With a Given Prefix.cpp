#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force usign .find()
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

// Approach 2: Brute Force using .substr()
// Time Complexity: O(n * m), where n = number of words in the vector and m = length of the prefix string `pref`.
// Space Complexity: O(1), as no additional data structures are used apart from variables.
class Solution
{
public:
  int prefixCount(vector<string> &words, string pref)
  {
    int count = 0;         // Initialize a counter to keep track of words matching the prefix.
    int n = pref.length(); // Store the length of the prefix string for repeated use.

    // Iterate through each word in the `words` vector.
    for (string &word : words)
    {
      // Extract the first `n` characters of the current word using `substr`.
      // Compare them with the prefix `pref`.
      if (word.substr(0, n) == pref)
      {
        count++; // Increment the counter if the extracted substring matches the prefix.
      }
    }

    // Return the total count of words that start with the prefix `pref`.
    return count;
  }
};