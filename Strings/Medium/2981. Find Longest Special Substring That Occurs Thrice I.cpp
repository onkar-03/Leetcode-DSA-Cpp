#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force - Try all possible substrings)
// T.C : O(n^3)
// S.C : O(n^2), total substrings
class Solution
{
public:
  int maximumLength(string s)
  {
    int n = s.length();

    map<string, int> mp; //"substring, int"
    for (int i = 0; i < n; i++)
    {
      string curr;
      for (int j = i; j < n; j++)
      {
        if (curr.empty() || curr.back() == s[j])
        {
          curr.push_back(s[j]);
          mp[curr]++;
        }
        else
        {
          break;
        }
      }
    }

    int result = 0;
    for (auto &it : mp)
    {
      string str = it.first;
      int count = it.second;
      if (count >= 3 && str.length() > result)
      {
        result = str.length();
      }
    }

    return result == 0 ? -1 : result;
  }
};