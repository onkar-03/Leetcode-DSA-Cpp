#include <bits/stdc++.h>
using namespace std;

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
