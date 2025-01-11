#include <bits/stdc++.h>
using namespace std;

// Approach - (Using the fact that odd frequency characters count control the palindromes count)
// T.C : O(n)
// S.C : O(26) ~ O(1)
class Solution
{
public:
  // Function to determine if it is possible to construct `k` palindromic strings from the input string `s`
  bool canConstruct(string s, int k)
  {
    // Calculate the length of the string
    int n = s.length();

    // If the length of the string is less than `k`, it's impossible to construct `k` palindromic strings
    if (n < k)
    {
      return false;
    }

    // If the length of the string equals `k`, it's always possible to construct exactly `k` palindromic strings
    if (n == k)
    {
      return true;
    }

    // Create a vector to store the frequency of each character in the string
    // `vec[i]` will store the frequency of the character `i + 'a'`
    vector<int> vec(26, 0);

    // Count the frequency of each character in the string
    for (char &ch : s)
    {
      vec[ch - 'a']++;
    }

    // Variable to count the number of characters with odd frequencies
    int oddFreqCharCount = 0;

    // Traverse the frequency array to calculate the count of characters with odd frequencies
    for (int i = 0; i < 26; i++)
    {
      if (vec[i] % 2 != 0)
      { // If frequency is odd
        oddFreqCharCount++;
      }
    }

    // If the count of characters with odd frequencies is less than or equal to `k`,
    // it's possible to construct `k` palindromic strings.
    // Otherwise, it's not possible.
    return oddFreqCharCount <= k;
  }
};
