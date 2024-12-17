#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using pointers and frequency table)
// Time Complexity : O(n) - Processing all characters in the string.
// Space Complexity : O(26) - Constant space for frequency table of lowercase letters.
class Solution
{
public:
  string repeatLimitedString(string s, int repeatLimit)
  {
    // Step 1: Frequency table to count occurrences of each character
    vector<int> count(26, 0); // S.C : O(26), constant space for 26 lowercase letters
    for (char &ch : s)
    { // T.C : O(n), iterate through the string to fill frequency table
      count[ch - 'a']++;
    }

    string result; // Resultant string to store the final answer.

    int i = 25; // Start from 'z' (index 25), the largest character.
    while (i >= 0)
    { // O(26) - Loop through the 26 letters
      // Skip characters with zero frequency
      if (count[i] == 0)
      {
        i--;
        continue;
      }

      // Step 2: Append up to 'repeatLimit' occurrences of the current character
      char ch = 'a' + i;                     // Convert index to character
      int freq = min(count[i], repeatLimit); // Limit the frequency to 'repeatLimit'
      result.append(freq, ch);               // Append the character 'freq' times
      count[i] -= freq;                      // Update the remaining count for this character

      // Step 3: If characters still remain, append a smaller character to "break" the repetition
      if (count[i] > 0)
      {
        // Find the next largest character (smaller than current one)
        int j = i - 1;
        while (j >= 0 && count[j] == 0)
        { // Move to the next valid character
          j--;
        }

        // If no smaller character exists, terminate the process
        if (j < 0)
        {
          break;
        }

        // Append one occurrence of the smaller character to "break" the repeat chain
        // result.append(1,'a' + j);
        result.push_back('a' + j);

        // Reduce the freq of the current character
        count[j]--;
      }
    }

    // Step 4: Return the resultant string
    return result;
  }
};
