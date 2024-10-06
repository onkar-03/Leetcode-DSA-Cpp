#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using pointers to compare words from both ends)
// T.C : O(m+n) where m and n are the number of words in s1 and s2 respectively
// S.C : O(m+n) for storing the words from both sentences in vectors

class Solution
{
public:
  bool areSentencesSimilar(string s1, string s2)
  {
    // If s2 is longer than s1, we swap them so s1 is always the longer or equal-length sentence.
    if (s1.length() < s2.length())
    {
      swap(s1, s2);
    }

    // Vectors to store the words of each sentence
    vector<string> vec1, vec2;
    string token;

    // Split s1 into words and store in vec1
    stringstream ss1(s1); // Create a stringstream object to parse the sentence s1
    while (ss1 >> token)  // Extract words from s1 (using space as the delimiter)
    {
      vec1.push_back(token); // Push each extracted word into vec1
    }

    // Split s2 into words and store in vec2
    stringstream ss2(s2); // Create a stringstream object to parse the sentence s2
    while (ss2 >> token)  // Extract words from s2 (using space as the delimiter)
    {
      vec2.push_back(token); // Push each extracted word into vec2
    }

    // i and j will point to the start and end of vec1 (s1's words)
    int i = 0, j = vec1.size() - 1;

    // k and l will point to the start and end of vec2 (s2's words)
    int k = 0, l = vec2.size() - 1;

    // Compare words from the start of both sentences
    // Continue while the words match, increment i and k (pointers to the beginning)
    while (i < vec1.size() && k < vec2.size() && vec1[i] == vec2[k])
    {
      i++; // Move the pointer in vec1 to the next word
      k++; // Move the pointer in vec2 to the next word
    }

    // Compare words from the end of both sentences
    // Continue while the words match, decrement j and l (pointers to the end)
    while (l >= k && vec1[j] == vec2[l])
    {
      j--; // Move the pointer in vec1 backward
      l--; // Move the pointer in vec2 backward
    }

    // If l < k, it means that all words in vec2 are part of vec1 (either from the start or end)
    return l < k;
  }
};
