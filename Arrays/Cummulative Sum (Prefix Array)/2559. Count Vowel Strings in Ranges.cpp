#include <bits/stdc++.h>
using namespace std;

// Approach: Using Cumulative Sum Array (Prefix Sum Array)
// Time Complexity: O(N + Q), where N is the size of `words` and Q is the number of queries.
// Space Complexity: O(N), for storing the cumulative sum array
class Solution
{
public:
  // Helper function to check if a character is a vowel
  bool isVowel(char &ch)
  {
    // Check if the character is one of 'a', 'e', 'i', 'o', 'u'
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
      return true;
    return false;
  }

  vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
  {
    int Q = queries.size(); // Number of queries
    int N = words.size();   // Number of words in the input
    vector<int> result(Q);  // Result array to store answers for each query

    vector<int> cumSum(N); // Cumulative sum array to store the count of vowel strings
    int sum = 0;           // Variable to maintain the running sum

    // Iterate through each word in the `words` array
    for (int i = 0; i < N; i++)
    { // O(N)
      // Check if the first and last characters of the word are vowels
      if (isVowel(words[i][0]) && isVowel(words[i].back()))
      {
        sum++; // Increment the count if the condition is true
      }
      cumSum[i] = sum; // Update the cumulative sum at index i
    }

    // Iterate through each query
    for (int i = 0; i < Q; i++)
    {                        // O(Q)
      int l = queries[i][0]; // Left index of the query range
      int r = queries[i][1]; // Right index of the query range

      // Calculate the result for the current query using the cumulative sum array
      result[i] = cumSum[r] - ((l > 0) ? cumSum[l - 1] : 0);
    }

    return result; // Return the result array
  }
};
