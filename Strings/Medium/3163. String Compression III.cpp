#include <bits/stdc++.h>
using namespace std;

// Approach (Simple Simulation)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
  // Function to return a compressed version of the input string
  string compressedString(string word)
  {
    // Initialize an empty string to store the compressed result
    string comp = "";

    // Get the length of the input string
    int n = word.length();
    // Initialize index variable
    int i = 0;

    // Loop through the input string until the end
    while (i < n)
    {
      // Initialize count to keep track of the frequency of the current character
      int count = 0;
      // Store the current character for comparison
      char ch = word[i];

      // Loop to count consecutive occurrences of the same character, with a maximum of 9
      while (i < n && count < 9 && word[i] == ch)
      {
        count++; // Increment count for each occurrence of the character
        i++;     // Move to the next character
      }

      // Append the count and the character to the compressed string
      comp += to_string(count) + ch;
    }

    // Return the final compressed string
    return comp;
  }
};
