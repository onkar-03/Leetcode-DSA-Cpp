#include <bits/stdc++.h> // Include all standard libraries
using namespace std;     // Use the standard namespace to avoid prefixing standard types and functions

// Define the Trie class
class Trie
{
public:
  // Define the structure for a Trie Node
  struct trieNode
  {
    bool isEndOfWord;       // Indicates if the node marks the end of a word
    trieNode *children[26]; // Array to hold pointers to children (26 for each letter of the alphabet)
  };

  // Function to create a new Trie Node
  trieNode *getNode()
  {
    // Allocate memory for a new Trie Node
    trieNode *newNode = new trieNode();

    // Initialize isEndOfWord to false
    newNode->isEndOfWord = false;

    // Initialize all children to NULL
    for (int i = 0; i < 26; i++)
    {
      // Set all child pointers to NULL
      newNode->children[i] = NULL;
    }
    // Return the newly created node
    return newNode;
  }

  trieNode *root; // Pointer to the root node of the Trie

  // Constructor to initialize the Trie
  Trie()
  {
    // Initialise the root pointer to the newly created Node
    root = getNode();
  }

  // Function to insert a word into the Trie
  void insert(string word)
  {
    // Start at the root node
    trieNode *crawler = root; 

    // Iterate over each character in the word
    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];  // Get the current character
      int idx = ch - 'a'; // Calculate the index (0-25) for the character

      // If the child pointer for the current character is NULL, create a new node
      if (crawler->children[idx] == NULL)
      {
        crawler->children[idx] = getNode(); // Allocate a new node for this character
      }
      
      // Move to the next node in the Trie
      crawler = crawler->children[idx]; // Update crawler to the child node
    }
    crawler->isEndOfWord = true; // Mark the end of the word
  }

  // Function to search for a word in the Trie
  bool search(string word)
  {
    trieNode *crawler = root; // Start at the root node

    // Iterate over each character in the word
    for (int i = 0; i < word.length(); i++)
    {
      char ch = word[i];  // Get the current character
      int idx = ch - 'a'; // Calculate the index (0-25) for the character
      // If the child pointer is NULL, the word does not exist
      if (crawler->children[idx] == NULL)
      {
        return false; // Return false if character not found
      }
      // Move to the next node in the Trie
      crawler = crawler->children[idx]; // Update crawler to the child node
    }
    // Check if the current node marks the end of a word
    if (crawler != NULL && crawler->isEndOfWord == true)
    {
      return true; // Return true if word found
    }
    return false; // Return false if word not found
  }

  // Function to check if any word in the Trie starts with the given prefix
  bool startsWith(string prefix)
  {
    trieNode *crawler = root; // Start at the root node
    int i = 0;                // Initialize index variable
    // Iterate over each character in the prefix
    for (i; i < prefix.length(); i++)
    {
      char ch = prefix[i]; // Get the current character
      int idx = ch - 'a';  // Calculate the index (0-25) for the character

      // If the child pointer is NULL, there is no word with this prefix
      if (crawler->children[idx] == NULL)
      {
        return false; // Return false if prefix not found
      }
      // Move to the next node in the Trie
      crawler = crawler->children[idx]; // Update crawler to the child node
    }
    // If all characters in the prefix are found, return true
    if (i == prefix.length())
    {
      return true; // Return true if prefix found
    }
    return false; // Return false if prefix not found
  }
};
