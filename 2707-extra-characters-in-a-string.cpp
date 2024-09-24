#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // As max size given is 50 for dictionary array
  int t[51];
  int solve(int i, string &s, unordered_set<string> &dictSet, int &length)
  {
    // Out of bounds (base case)
    if (i >= length)
    {
      return 0;
    }

    if (t[i] != -1)
    {
      return t[i];
    }

    // Case 1: Skip the current character and count it as extra
    int result = 1 + solve(i + 1, s, dictSet, length);

    // Case 2: Try to match substrings from current position to any future
    // position Start j from same as i as a single starting character can
    // also be put as a word in teh dictionary as well
    for (int j = i; j < length; j++)
    {
      // Extract the substring from i to j
      string sub = s.substr(i, j - i + 1);

      // If the substring is found in the dictionary, then recursively
      // call the function for the next substring .count() to search for
      // the substring in the dictSet
      if (dictSet.count(sub))
      {
        // If the substring is found in the dictionary, then recursively
        // call the function for the next substring
        result = min(result, solve(j + 1, s, dictSet, length));
      }
    }

    return t[i] = result;
  }

  int minExtraChar(string s, vector<string> dict)
  {

    // Convert the array of strings to set, so that we can compare the words
    // in teh dictionary in O(N) Time
    unordered_set<string> dictSet(dict.begin(), dict.end());

    memset(t, -1, sizeof(t));

    // Length of String
    int length = s.length();

    // Solve and count number of extra characters
    // 0 is the Start Index of String
    return solve(0, s, dictSet, length);
  }
};

int main()
{
  Solution solution;

  string s = "leetscode";
  vector<string> dictionary = {"leet", "code", "leetcode"};

  int ans = solution.minExtraChar(s, dictionary);
  cout << "Extra Characters: " << ans;
  return 0;
}