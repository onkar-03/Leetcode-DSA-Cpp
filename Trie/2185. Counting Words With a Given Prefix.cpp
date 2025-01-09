#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force using .find()
// Time Complexity: O(n * m), where n = number of words in the vector and m = length of the prefix string `pref`.
// Space Complexity: O(1), as no extra space is used apart from variables.
class Solution
{
public:
  int prefixCount(vector<string> &words, string pref)
  {
    int count = 0; // Initialize a counter to store the number of words that match the prefix.

    // Iterate through each word in the vector `words`.
    for (string &word : words)
    {
      // Check if the current word starts with the prefix `pref`.
      // `word.find(pref) == 0` means the prefix matches the start of the word.
      if (word.find(pref) == 0)
      {
        count++; // Increment the counter if the prefix matches.
      }
    }

    // Return the total count of words that start with the prefix `pref`.
    return count;
  }
};

// Approach 2: Brute Force using .substr()
// Time Complexity: O(n * m), where n = number of words in the vector and m = length of the prefix string `pref`.
// Space Complexity: O(1), as no additional data structures are used apart from variables.
class Solution
{
public:
  int prefixCount(vector<string> &words, string pref)
  {
    int count = 0;         // Initialize a counter to keep track of words matching the prefix.
    int n = pref.length(); // Store the length of the prefix string for repeated use.

    // Iterate through each word in the `words` vector.
    for (string &word : words)
    {
      // Extract the first `n` characters of the current word using `substr`.
      // Compare them with the prefix `pref`.
      if (word.substr(0, n) == pref)
      {
        count++; // Increment the counter if the extracted substring matches the prefix.
      }
    }

    // Return the total count of words that start with the prefix `pref`.
    return count;
  }
};

// Approach 3: (Using Trie)
// Time Complexity (T.C): O(n * l + m), where n = number of words, m = length of the prefix, l = average length of a word
// Space Complexity (S.C): O(n * l)
struct trieNode
{
  trieNode *children[26]; // Array to store pointers to child nodes (for each letter 'a' to 'z')
  bool isEndOfWord;       // Flag to mark the end of a word
  int count;              // Count of words/prefixes ending at this node

  // Constructor to initialize the trieNode
  trieNode()
  {
    isEndOfWord = false;
    count = 0;
    for (int i = 0; i < 26; i++)
    {
      children[i] = NULL;
    }
  }
};

// Function to create and return a new trieNode
trieNode *getNode()
{
  return new trieNode();
}

// Trie class to manage the insertion and searching of words
class Trie
{
public:
  trieNode *root; // Root node of the Trie

  // Constructor to initialize the Trie with an empty root node
  Trie()
  {
    root = getNode();
  }

  // Function to insert a word into the Trie
  void insert(string &word)
  { // Time Complexity: O(l), where l is the length of the word
    trieNode *pCrawl = root;
    for (char &ch : word)
    {                     // Traverse through each character of the word
      int idx = ch - 'a'; // Calculate index for the character
      if (pCrawl->children[idx] == NULL)
      {
        // Create a new node if the corresponding child doesn't exist
        pCrawl->children[idx] = getNode();
      }
      pCrawl = pCrawl->children[idx]; // Move to the child node
      pCrawl->count++;                // Increment the count for the prefix ending at this node
    }
    pCrawl->isEndOfWord = true; // Mark the end of the word
  }

  // Function to search for the count of words with a given prefix
  int searchPrefixCount(string &pref)
  {
    trieNode *pCrawl = root;
    for (char &ch : pref)
    {                     // Traverse through each character of the prefix
      int idx = ch - 'a'; // Calculate index for the character
      if (pCrawl->children[idx] == NULL)
      {
        // If a child node for the character doesn't exist, prefix not found
        return 0;
      }
      pCrawl = pCrawl->children[idx]; // Move to the child node
    }
    return pCrawl->count; // Return the count of words with the given prefix
  }
};

class Solution
{
public:
  // Main function to count the number of words with the given prefix
  int prefixCount(vector<string> &words, string pref)
  {
    Trie trie; // Create a Trie object

    // Insert all words into the Trie
    for (string &word : words)
    { // Time Complexity: O(n * l), where n is the number of words
      trie.insert(word);
    }

    // Search for the count of words with the given prefix
    return trie.searchPrefixCount(pref); // Time Complexity: O(m), where m is the length of the prefix
  }
};
