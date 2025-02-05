#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1 : Using Character Frequency and Mismatch Count
 * - This approach checks if two strings are almost equal by counting the positions where characters differ. If they are already equal, we return true immediately.
 * - We then iterate through both strings, counting the differing positions. If there are more than two differing positions, we return false (since only one swap is allowed).
 * - We also track the frequency of characters in both strings using unordered_maps. After processing both strings, we compare the frequency maps.
 * - If the character frequencies match, we return true, indicating that swapping two characters could make the strings equal. Otherwise, return false.
 * ---------------------------
 * T.C : O(n) - We iterate through the strings once (O(n)) to count character mismatches and store frequencies, followed by a single check over 26 characters (O(26))
 * ---------------------------
 * S.C : O(1) - The unordered_map stores at most 26 characters, which is constant space.
 */

class Solution
{
public:
  bool areAlmostEqual(string s1, string s2)
  {
    int n = s1.length(); // Get the length of the strings

    // If both strings are already equal, return true
    if (s1 == s2)
    {
      return true;
    }

    int diffIndx = 0; // Count of differing indices

    unordered_map<char, int> mp1, mp2; // Maps to store character frequencies

    // Traverse the strings
    for (int i = 0; i < n; i++)
    {
      if (s1[i] != s2[i])
      {
        diffIndx++; // Count mismatched indices
      }

      // If more than two mismatches, swapping won't make them equal
      if (diffIndx > 2)
      {
        return false;
      }

      mp1[s1[i]]++; // Store frequency of characters in s1
      mp2[s2[i]]++; // Store frequency of characters in s2
    }

    // Check if both maps have the same character frequency
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
      if (mp1[ch] != mp2[ch])
      {
        return false;
      }
    }
    return true;
  }
};

/*
 * Approach-2 : Using Map and Vector for Frequency Counting
 * - This approach works similarly to the first one but uses vectors instead of unordered maps to store the frequency of characters.
 * - We iterate through both strings, counting the differing positions and character frequencies using two separate vectors.
 * - After processing both strings, we check if the frequency vectors are the same.
 * - If the frequencies match, we return true, indicating that swapping two characters could make the strings equal. Otherwise, return false
 * ---------------------------
 * T.C: O(n) - We iterate over the strings once (O(n)) to count character mismatches and store frequencies, followed by a single check over 26 characters (O(26))
 * ---------------------------
 * S.C: O(26) ~= O(1) - We use two vectors of size 26 to store character frequencies.
 */
class Solution
{
public:
  bool areAlmostEqual(string s1, string s2)
  {
    int n = s1.length(); // Get the length of the strings

    // If both strings are already equal, return true
    if (s1 == s2)
    {
      return true;
    }

    int diffs = 0; // Count of differing indices

    vector<int> freq1(26, 0), freq2(26, 0); // Vectors to store character frequencies

    // Traverse the strings
    for (int i = 0; i < n; i++)
    {
      if (s1[i] != s2[i])
      {
        diffs++; // Count mismatched indices
      }

      // If more than two mismatches, swapping won't make them equal
      if (diffs > 2)
      {
        return false;
      }

      freq1[s1[i] - 'a']++; // Store frequency of characters in s1
      freq2[s2[i] - 'a']++; // Store frequency of characters in s2
    }

    // Check if both frequency vectors are the same
    for (int i = 0; i < 26; i++)
    {
      if (freq1[i] != freq2[i])
      {
        return false;
      }
    }

    return true;
  }
};

/*
 * Approach-2 (Using Counting Only. No Map Required)
 * - This approach checks if two strings are almost equal by counting the positions where characters differ. If they are already equal, we return true immediately.
 * - We then iterate through both strings, counting the differing positions. If there are more than two differing positions, we return false (since only one swap is allowed).
 * - We store the indices of the first two mismatches and check if swapping the characters at these indices can make the strings equal.
 * ---------------------------
 * T.C : O(n) - We iterate through the strings once (O(n)) to count the number of mismatches and store the indices of the first two mismatches
 * ---------------------------
 * S.C : O(1) - Only a few integer variables are used to track the mismatches, which is constant space.
 */
class Solution
{
public:
  bool areAlmostEqual(string s1, string s2)
  {
    int n = s1.length(); // Get the length of the strings

    // If the strings are already equal, return true
    if (s1 == s2)
    {
      return true;
    }

    int diffs = 0;     // Count of differing positions
    int firstIdx = 0;  // Store the first mismatch index
    int secondIdx = 0; // Store the second mismatch index

    // Traverse through the strings
    for (int i = 0; i < n; i++)
    {
      // If the characters are different at the current position
      if (s1[i] != s2[i])
      {
        diffs++; // Increment the mismatch count

        // If there are more than two mismatches, return false
        if (diffs > 2)
        {
          return false;
        }
        else if (diffs == 1)
        {
          firstIdx = i; // Store the first mismatch index
        }
        else
        {
          secondIdx = i; // Store the second mismatch index
        }
      }
    }

    // If there are exactly two mismatches, check if swapping can make the strings equal
    return s1[firstIdx] == s2[secondIdx] && s1[secondIdx] == s2[firstIdx];
  }
};
