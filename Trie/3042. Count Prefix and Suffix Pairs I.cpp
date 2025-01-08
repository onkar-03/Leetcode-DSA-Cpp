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

// Approach-2 - Using TRIE
// T.C : ~O(n^2*l), n = number of words, l = average length of each word
// S.C : ~O(n*l), need to store all characters of words

//  Trie Node Structure: Represents each node in the Trie.
struct trieNode
{
  trieNode *children[26]; // Each node can have up to 26 children, one for each letter of the alphabet.
  bool isEndOfWord;       // Indicates whether the current node is the end of a word.
};

// Function to create a new Trie node and initialize its members.
trieNode *getNode()
{
  trieNode *newNode = new trieNode();
  newNode->isEndOfWord = false; // New node is not the end of a word initially.
  // Initialize all children pointers to NULL.
  for (int i = 0; i < 26; i++)
  {
    newNode->children[i] = NULL;
  }
  return newNode;
}

// Trie class with functions for inserting words and searching prefixes.
class Trie
{
public:
  trieNode *root; // Root node of the Trie.

  // Constructor initializes the root node.
  Trie()
  {
    root = getNode();
  }

  // Inserts a word into the Trie.
  void insert(string word)
  {
    trieNode *pCrawl = root; // Start from the root.
    // Traverse each character in the word.
    for (int i = 0; i < word.length(); i++)
    {
      int idx = word[i] - 'a'; // Find the index for the character (0-25).
      // If the child node for the current character doesn't exist, create it.
      if (pCrawl->children[idx] == NULL)
      {
        pCrawl->children[idx] = getNode();
      }
      // Move to the next child node.
      pCrawl = pCrawl->children[idx];
    }
    pCrawl->isEndOfWord = true; // Mark the end of the word.
  }

  // Checks if a given prefix exists in the Trie.
  bool searchPrefix(string prefix)
  {
    trieNode *pCrawl = root; // Start from the root.
    // Traverse each character in the prefix.
    for (int i = 0; i < prefix.length(); i++)
    {
      int idx = prefix[i] - 'a'; // Find the index for the character (0-25).
      // If the child node doesn't exist, return false.
      if (pCrawl->children[idx] == NULL)
      {
        return false;
      }
      // Move to the next child node.
      pCrawl = pCrawl->children[idx];
    }
    return true; // Prefix exists.
  }
};

// Solution class with the method to count prefix-suffix pairs.
class Solution
{
public:
  int countPrefixSuffixPairs(vector<string> &words)
  {
    int n = words.size(); // Get the total number of words.
    int count = 0;        // To count the valid prefix-suffix pairs.

    // Iterate over each word in the list.
    for (int j = 0; j < n; j++)
    {
      Trie prefixTrie; // Trie to store prefixes of the current word.
      Trie suffixTrie; // Trie to store suffixes (reversed words) of the current word.

      // Insert the word into the prefix Trie.
      prefixTrie.insert(words[j]);
      // Reverse the word to check for suffixes.
      string reversed = words[j];
      reverse(begin(reversed), end(reversed));
      // Insert the reversed word into the suffix Trie.
      suffixTrie.insert(reversed);

      // Now, for each previous word (i < j), check if it's a valid prefix-suffix pair.
      for (int i = 0; i < j; i++)
      {
        // Skip words that are longer than the current word (since they can't be a valid prefix).
        if (words[i].length() > words[j].length())
        {
          continue;
        }

        // Reverse the current word[i] to check it as a suffix.
        string rev = words[i];
        reverse(begin(rev), end(rev));

        // If the current word[i] is a valid prefix and rev is a valid suffix, count the pair.
        if (prefixTrie.searchPrefix(words[i]) == true && suffixTrie.searchPrefix(rev) == true)
        {
          count++; // Valid pair found.
        }
      }
    }

    return count; // Return the total number of valid prefix-suffix pairs.
  }
};
