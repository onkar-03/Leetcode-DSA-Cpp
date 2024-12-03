#include <bits/stdc++.h>
using namespace std;

// Approach: Simple traversal using two pointers
// Time Complexity (T.C): O(m + n)
// - m: Length of the input string `s`
// - n: Number of elements in the `spaces` vector
// Space Complexity (S.C): O(1) (excluding the space used by the result string)
class Solution
{
public:
  string addSpaces(string s, vector<int> &spaces)
  {
    // Get the length of the input string and the spaces vector
    int m = s.length();
    int n = spaces.size();

    // Initialize the result string to store the final output
    string result = "";

    // Pointer `j` is used to traverse the `spaces` vector
    int j = 0;

    // Traverse through each character of the input string `s`
    for (int i = 0; i < m; i++)
    {
      // Check if the current index `i` matches the value at spaces[j]
      if (j < n && i == spaces[j])
      {
        // If true, append a space to the result string
        result += " ";
        // Move to the next index in the `spaces` vector
        j++;
      }
      // Append the current character of `s` to the result string
      result += s[i];
    }

    // Return the final result string with spaces added
    return result;
  }
};
