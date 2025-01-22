#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 (Using Sorting)
 * ---------------------------
 * Time Complexity: O(n * k * log(k))
 * - We iterate over each string in the input (n strings). For each string, we sort it, which takes O(k * log(k)),
 * where k is the maximum length of a string in the input.
 *
 * Space Complexity: O(n * k)
 * - We store the strings in an unordered map, where the total number of characters stored is O(n * k),
 * and the strings themselves take O(k) space.
 */

class Solution
{
public:
  // Declare a function that takes a vector of strings as input and returns a vector of vector of strings
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {

    // Create an unordered map to store sorted strings as keys and their corresponding anagrams as values
    unordered_map<string, vector<string>> mp;

    // Traverse through each string in the input vector
    for (auto str : strs)
    {

      // Make a copy of the current string to sort it
      string temp = str;

      // Sort the characters of the string
      sort(temp.begin(), temp.end());

      // Add the original string to the vector of anagrams for the sorted string
      mp[temp].push_back(str);
    }

    // Create a vector to hold the result, which is a vector of anagram groups
    vector<vector<string>> result;

    // Traverse through the unordered map and add each vector of anagrams to the result vector
    for (auto it : mp)
    {
      result.push_back(it.second);
    }

    // Return the result vector containing the grouped anagrams
    return result;
  }
};
