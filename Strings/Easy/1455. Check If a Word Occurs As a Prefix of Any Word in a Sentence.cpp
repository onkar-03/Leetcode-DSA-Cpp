#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(words * n), where 'words' is the total number of words in the sentence and 'n' is the length of the searchWord. This accounts for traversing each word and comparing its prefix with the searchWord.
// Space Complexity: O(1), as we use a constant amount of extra space.

class Solution
{
public:
  int isPrefixOfWord(string sentence, string searchWord)
  {
    stringstream ss(sentence); // Used to split the sentence into words
    string token = "";         // Temporary variable to store each word
    int index = 1;             // 1-based index to track the word's position

    // Split the sentence into words using the stringstream
    while (getline(ss, token, ' '))
    {
      // Check if the word starts with 'searchWord'
      if (token.find(searchWord, 0) == 0)
      {
        return index; // Return the 1-based index if a match is found
      }
      index++; // Increment the index for the next word
    }

    return -1; // Return -1 if no match is found
  }
};
