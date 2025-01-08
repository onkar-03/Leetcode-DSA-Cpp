#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force using .find() Method
// Time Complexity: O(n^2 * l)
// - Outer loop runs n times, and the inner loop runs approximately n/2 times on average, resulting in O(n^2).
// - String operations (find and rfind) for prefix and suffix checking take O(l), where l is the average length of strings.
// - Overall: O(n^2 * l)

// Space Complexity: O(1)
// - No additional data structures are used.
// - Strings str1 and str2 are references to existing strings in the input vector, so no extra memory is allocated.

class Solution
{
public:
  int countPrefixSuffixPairs(vector<string> &words)
  {
    int count = 0; // Initialize a counter to track the number of valid prefix-suffix pairs

    // Outer loop to iterate through each word in the list
    for (int i = 0; i < words.size(); i++)
    {
      // Inner loop starts from i + 1 to ensure we only compare pairs (i, j) where i < j
      for (int j = i + 1; j < words.size(); j++)
      {
        string str1 = words[i]; // Current word at index i
        string str2 = words[j]; // Current word at index j

        int n = str1.length(); // Length of the first word (str1)
        int m = str2.length(); // Length of the second word (str2)

        // Only proceed if str1 is shorter or equal in length to str2, otherwise str1 cant be a prefix / suffix of str2
        {
          if (n <= m)
            // Check if str1 is a prefix or suffix of str2
            // str2.find(str1) == 0 -> str1 is a prefix of str2
            // str2.rfind(str1) == (m - n) -> str1 is a suffix of str2
            if (str2.find(str1) == 0 && str2.rfind(str1) == (m - n))
            {
              count++; // Increment the counter for valid prefix-suffix pairs
            }
        }
      }
    }

    return count; // Return the total count of prefix-suffix pairs
  }
};

// Approach: Brute Force with Substring Comparison .substr()
// Time Complexity: O(n^2 * l)
// - Outer loop runs n times, and the inner loop runs n/2 times on average, resulting in O(n^2).
// - String operations `substr` take O(l), where l is the length of the string.
// - Total: O(n^2 * l)

// Space Complexity: O(1)
// - No extra data structures are used, and only temporary variables are created.
class solution
{
public:
  int countPrefixSuffixPairs(vector<string> &words)
  {
    int count = 0; // Initialize a counter to keep track of valid prefix-suffix pairs

    // Outer loop to iterate through each word in the list
    for (int i = 0; i < words.size(); i++)
    {
      // Inner loop starts from i + 1 to ensure we only compare pairs (i, j) where i < j
      for (int j = i + 1; j < words.size(); j++)
      {
        string str1 = words[i]; // Current word at index i
        string str2 = words[j]; // Current word at index j

        int n = str1.length(); // Length of str1
        int m = str2.length(); // Length of str2

        // Check if str1 is both a prefix and suffix of str2
        // Use substr to extract the prefix and suffix of str2
        if (str2.substr(0, n) == str1 && str2.substr(m - n, n) == str1)
        {
          count++; // Increment the count for valid prefix-suffix pairs
        }
      }
    }

    return count; // Return the total count of prefix-suffix pairs
  }
};
