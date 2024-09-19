
#include <bits/stdc++.h>
using namespace std;

/*
    Given array of strings, group anagrams together (same letters diff order)
    Ex. strs = ["eat","tea","tan","ate","nat","bat"] -> [["bat"],["nat","tan"],["ate","eat","tea"]]

    Count chars, for each string use total char counts (naturally sorted) as key

    Time: O(n x l) -> n = length of strs, l = max length of a string in strs
    Space: O(n x l)
*/

// --- Hash Map Solution
class Solution
{
public:
  // Function to group anagrams from the input vector of strings
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    // Create a hash map to store groups of anagrams
    unordered_map<string, vector<string>> anagramMap;

    // Iterate through each string in the input vector
    for (int i = 0; i < strs.size(); i++)
    {
      // Generate a key for the current string to identify anagrams
      string key = getKey(strs[i]);
      // Add the current string to the appropriate group in the map
      anagramMap[key].push_back(strs[i]);
    }

    // Vector to store the result, which is a vector of vector of strings
    vector<vector<string>> result;

    // Iterate through the map and add each group of anagrams to the result
    for (auto i = anagramMap.begin(); i != anagramMap.end(); i++)
    {
      result.push_back(i->second);
    }

    // Return the result containing grouped anagrams
    return result;
  }

private:
  // Function to generate a key for a string that will be the same for anagrams
  string getKey(string &str)
  {
    // Create an array to count occurrences of each character (assuming all characters are lowercase)
    vector<int> count(26, 0);

    // Iterate through each character in the string
    for (int i = 0; i < str.size(); i++)
    {
      // Increment the count for the character
      count[str[i] - 'a']++;
    }

    // Create a string to store the key
    string key = "";
    // Convert the count array into a string key
    for (int i = 0; i < count.size(); i++)
    {
      // Append the count and a delimiter to the key string
      key.append(to_string(count[i]) + '#');
    }
    // Return the generated key
    return key;
  }
};

int main()
{
  // Create an instance of the Solution class
  Solution solution;

  // Define a vector of strings for testing
  vector<string> check = {"eat", "tea", "tan", "ate", "nat", "bat"};
  // Group anagrams using the Solution class method
  vector<vector<string>> result = solution.groupAnagrams(check);

  // Iterate through each group of anagrams in the result
  for (const auto &group : result)
  {
    // Print each word in the current group
    for (const auto &word : group)
    {
      cout << word << " "; // Print the word followed by a space
    }
    cout << endl; // Print a newline after each group
  }
  return 0; // Return 0 to indicate successful completion
}