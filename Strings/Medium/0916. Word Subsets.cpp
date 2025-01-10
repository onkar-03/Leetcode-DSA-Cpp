#include <bits/stdc++.h>
using namespace std;

// Approach: Use character frequency counting with a map (fixed size vector for alphabets)
// Time Complexity: O(n * l1 + m * l2), where
//     - n = number of words in words2, l1 = average length of words in words2
//     - m = number of words in words1, l2 = average length of words in words1
// Space Complexity: O(26) ~= O(1) since we only store character frequencies for 26 lowercase English letters
class Solution
{
public:
  // Helper function to check if `freq2` is a subset of `temp`
  // Parameters:
  // - freq2: Frequency vector representing the maximum frequency of each character in words2
  // - temp: Frequency vector of the current word in words1
  // Returns:
  // - true if `freq2` is a subset of `temp`, false otherwise
  bool isSubset(vector<int> &freq2, vector<int> &temp)
  {
    for (int i = 0; i < 26; i++)
    { // Iterate over all 26 lowercase letters (O(1))
      if (temp[i] < freq2[i])
      {
        return false; // If any character in `freq2` exceeds `temp`, it's not a subset
      }
    }
    return true; // All characters in `freq2` are satisfied by `temp`
  }

  // Main function to find all words in `words1` that are universal to `words2`
  vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
  {
    vector<string> result; // Result vector to store the universal words

    vector<int> freq2(26, 0); // Frequency vector to store the maximum frequency of each character in words2

    // Step 1: Build the maximum frequency requirement for words2
    // Time complexity: O(n * l1)
    for (string &word : words2)
    {                     // Iterate through each word in words2 (O(n))
      int temp[26] = {0}; // Temporary frequency array for the current word

      for (char &ch : word)
      {                   // Iterate through each character in the word (O(l1))
        temp[ch - 'a']++; // Count the frequency of the current character

        // Update `freq2` to store the maximum frequency for each character
        freq2[ch - 'a'] = max(freq2[ch - 'a'], temp[ch - 'a']);
      }
    }

    // Step 2: Check each word in words1 against the frequency requirements in `freq2`
    // Time complexity: O(m * l2)
    for (string &word : words1)
    {                          // Iterate through each word in words1 (O(m))
      vector<int> temp(26, 0); // Frequency vector for the current word

      for (char &ch : word)
      {                   // Iterate through each character in the word (O(l2))
        temp[ch - 'a']++; // Count the frequency of the current character
      }

      // Check if the current word satisfies the subset condition
      if (isSubset(freq2, temp))
      {                         // O(1), as the size of `freq2` is fixed (26)
        result.push_back(word); // Add the word to the result if it meets the condition
      }
    }

    // Return the list of universal words
    return result;
  }
};
