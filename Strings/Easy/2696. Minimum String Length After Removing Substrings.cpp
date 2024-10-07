#include <bits/stdc++.h>
using namespace std;

// Approach-3 (Using 2 pointers = i : read, j ; write)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
  int minLength(string s)
  {
    int i = 0;          // Write pointer
    int j = 1;          // Read pointer
    int n = s.length(); // Get the length of the input string

    // Iterate until 'j' reaches the end of the string
    while (j < n)
    {
      // Case when the write pointer 'i' is less than 0
      if (i < 0)
      {
        // Increment the write pointer 'i'
        i++;
        // Write the character from the read pointer 'j' to the write pointer 'i'
        s[i] = s[j];
      }
      // Check if the characters at the write pointer 'i' and read pointer 'j' form a pair to be removed: "AB" or "CD"
      else if ((s[i] == 'A' && s[j] == 'B') || (s[i] == 'C' && s[j] == 'D'))
      {
        // If a removable pair is found, decrement the write pointer 'i'
        // This effectively removes the pair from the resultant string
        i--;
      }
      else
      {
        // If no pair is found, increment 'i' to write the character from 'j'
        i++;
        // Write the character from the read pointer 'j' to the write pointer 'i'
        s[i] = s[j];
      }
      // Increment the read pointer 'j' to continue reading the next character
      j++;
    }
    // Return the new length of the modified string
    // 'i + 1' gives the number of valid characters written in the modified string
    return i + 1;
  }
};
