#include <bits/stdc++.h>
using namespace std;

// Approach: Simple Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution
{
public:
  bool isCircularSentence(string sentence)
  {
    int n = sentence.length(); // Get the length of the sentence

    // Iterate through each character in the sentence
    for (int i = 0; i < n; i++)
    {
      // If the current character is a space, check if the characters
      // before and after it are the same; if not, return false
      if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
        return false;
    }

    // Check if the first and last characters are the same
    // to ensure the sentence is circular
    return sentence[0] == sentence[n - 1];
  }
};