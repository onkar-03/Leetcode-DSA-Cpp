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

// Approach-2: Using Max-Heap (Priority Queue) + Frequency Table
// Time Complexity: O(n) - Linear traversal of the input string and heap operations.
// Space Complexity: O(26) ≈ O(1) - Fixed space for frequency table and heap of size <= 26.

class Solution
{
public:
  string repeatLimitedString(string s, int repeatLimit)
  {
    // Step 1: Create a frequency table for all characters in the string
    vector<int> count(26, 0); // To store frequency of characters ('a' to 'z')
    for (char &ch : s)
    {
      count[ch - 'a']++; // Increment the frequency of the current character
    }

    // Step 2: Build a Max-Heap (priority queue) to process characters in descending order
    priority_queue<char> pq;
    for (int i = 0; i < 26; i++)
    {
      // Only if the characters are there in the Input String i.e. their frequency is greater than zero then we put it in the Heap
      if (count[i] > 0)
      {
        char ch = 'a' + i; // Convert index back to character
        pq.push(ch);       // Add the character to the heap
      }
    }

    string result; // To store the final output string

    // Step 3: Process the heap to form the repeat-limited string
    while (!pq.empty())
    {
      char ch = pq.top(); // Fetch the most frequent (largest lexicographical) character
      pq.pop();

      // Step 4: Append 'repeatLimit' or remaining occurrences of the current character
      int freq = min(count[ch - 'a'], repeatLimit);
      result.append(freq, ch); // Append 'freq' copies of 'ch' to the result

      // Reduce the count for 'ch'
      count[ch - 'a'] -= freq;

      // Step 5: Handle remaining characters in the heap
      // Looking for teh next greatest character present
      if (count[ch - 'a'] > 0 && !pq.empty())
      {
        // Fetch the next most frequent character
        char nextChar = pq.top();
        pq.pop();

        // Append one occurrence of 'nextChar' to avoid violating repeatLimit
        result.push_back(nextChar);
        count[nextChar - 'a']--;

        // If 'nextChar' still has remaining occurrences, push it back into the heap
        if (count[nextChar - 'a'] > 0)
        {
          pq.push(nextChar);
        }

        // Push the current character 'ch' back into the heap for further processing
        pq.push(ch);
      }
    }

    // Step 6: Return the constructed repeat-limited string
    return result;
  }
};
