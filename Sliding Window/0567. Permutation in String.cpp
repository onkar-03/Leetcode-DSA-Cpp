#include <bits/stdc++.h>
using namespace std;

// Approach-2 (Using Sorting and Comparing) - ACCEPTED
// T.C : O((m-n) * nlogn)
// S.C : O(n) coz creating substring of length n every time to check
class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    // Find length of both strings
    int n = s1.length();
    int m = s2.length();

    // If s1 is longer than s2, it cannot be a substring
    if (n > m)
      return false;

    // Sort the string s1
    sort(s1.begin(), s1.end());

    // Iterate over each substring of s2 of length equal to s1, as we want to check if s1 is a substring of s2
    for (int i = 0; i <= m - n; i++)
    {
      // Extract a substring of length n from s2 starting at index i
      string temp = s2.substr(i, n);

      // Sort the substring in order to compare with the sorted s1 string
      sort(temp.begin(), temp.end());

      // If the sorted substring matches the sorted s1, return true
      if (temp == s1)
        return true;
    }

    // No permutation found in s2
    return false;
  }
};