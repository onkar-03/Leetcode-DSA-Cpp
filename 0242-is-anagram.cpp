#include <bits/stdc++.h>
using namespace std;

/*
Given two strings 's' and 't', return true if 't' is an anagram of 's', and false otherwise.

Explanation:
- An anagram is a word formed by rearranging the letters of another word, using all the original letters exactly once.
- Anagrams are of same length
- The task is to compare two strings and determine if they are anagrams.
*/

class Solution
{
public:
  // Function to check if two strings are anagrams
  bool isAnagram(string s, string t)
  {
    // If the lengths of the strings are different, they cannot be anagrams
    if (s.size() != t.size())
      return false;

    unordered_map<char, int> smap; // Map to store the frequency of each character in string 's'
    unordered_map<char, int> tmap; // Map to store the frequency of each character in string 't'

    // Store the frequency of each character of strings in 'smap' and 'tmap'
    for (int i = 0; i < s.size(); i++)
    {
      smap[s[i]]++; // Increment the count of character s[i] in 'smap'
      tmap[t[i]]++; // Increment the count of character t[i] in 'tmap'
    }

    // Compare the frequency of each character in both maps
    for (int i = 0; i < smap.size(); i++)
    {
      // Check if the frequency count of character 'i' in smap is not equal to the frequency count in tmap
      if (smap[i] != tmap[i])
        return false; // Return false if there is a mismatch in the frequency counts
    }
    return true; // Return true if all frequency counts match
  }
};

int main()
{
  Solution solution; // Create an instance of the Solution class

  string s = "anagram"; // Input string 's'
  string t = "naaragm"; // Input string 't'

  // Call the function and store the result
  bool result = solution.isAnagram(s, t);

  // Output the result
  cout << (result ? "Is Anagram" : "Not an Anagram") << endl;

  return 0;
}
