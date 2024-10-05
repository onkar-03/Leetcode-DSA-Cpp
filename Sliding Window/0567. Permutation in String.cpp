#include <bits/stdc++.h>
using namespace std;

// Approach-2 (Using Sorting and Comparing)
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

// Approach-3 (Sliding Window)
// Time Complexity: O(m + n), where m is the length of s2 and n is the length of s1
// Space Complexity: O(26), since we're only storing the frequency of 26 lowercase letters

class Solution // Define a class named 'Solution'
{
public:
  bool checkInclusion(string s1, string s2)
  {
    // Get the length of s1 and s2
    int n = s1.length();
    int m = s2.length();

    // If s1 is longer than s2, then s1's permutation can't be a substring of s2
    if (n > m)
    {
      return false; // Return false immediately if s1 is longer than s2
    }

    // Create frequency arrays for both s1 and the sliding window in s2
    // Both arrays will have size 26 (since there are 26 lowercase letters)
    // Default initialised with 0
    vector<int> s1_freq(26, 0);
    vector<int> s2_freq(26, 0);

    // Loop through each character in s1 and fill the frequency array for s1
    for (auto ch : s1)
    {
      // Increment the frequency of the character in s1_freq
      s1_freq[ch - 'a']++;
    }

    // Initialize two pointers for the sliding window
    // 'i' is the starting index of the window
    // 'j' is the ending index of the window
    int i = 0;
    int j = 0;

    // Start iterating over s2 with a sliding window approach and continue until the window reaches the end of s2
    while (j < m)
    {
      // Add the character at s2[j] to the current window frequency of s2 that we created
      s2_freq[s2[j] - 'a']++;

      // Shrink the window if the window size exceeds n (length of s1)
      if (j - i + 1 > n)
      {
        // Remove the character at s2[i] from the window's frequency
        s2_freq[s2[i] - 'a']--;
        i++; // Move the start of the window forward
      }

      // If the frequency arrays of s1 and the current window match,it means the current window is a permutation of s1
      if (s1_freq == s2_freq)
      {
        // Return true if the current window is a permutation of s1
        return true;
      }

      // Move the end of the window to the right
      j++;
    }

    // If no matching permutation is found, return false
    return false;
  }
};
