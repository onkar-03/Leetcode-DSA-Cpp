#include <bits/stdc++.h>
using namespace std;

// Approach-1 - (Simple simulation)
// T.C : O(n)
// S.C : O(26) ~ O(1)
class Solution
{
public:
  int minimumLength(string s)
  {
    // Get the length of the input string
    int n = s.length();

    // Frequency array to track character counts
    // (for 26 lowercase English letters)
    vector<int> freq(26, 0);

    // Counter to keep track of the total number of
    // characters deleted
    int deleted = 0;

    // Iterate through each character in the string
    for (int i = 0; i < n; i++)
    {
      freq[s[i] - 'a'] +=
          1; // Increment the frequency of the current character

      // If the frequency of the current character reaches 3
      if (freq[s[i] - 'a'] == 3)
      {
        freq[s[i] - 'a'] -= 2; // Reduce the frequency by 2 (simulate
                               // deleting two characters)
        deleted += 2;          // Update the count of deleted characters
      }
    }

    // Return the length of the string after accounting for all deleted
    // characters
    return n - deleted;
  }
};
