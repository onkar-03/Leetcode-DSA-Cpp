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

// Approach-2 (simple deque)
// T.C : O(m + n), where m is the length of s1 and n is the length of s2
// S.C : O(m + n), as we are storing the words of both sentences in deques

class Solution
{
public:
  // Function to determine if two sentences are similar
  bool areSentencesSimilar(string s1, string s2)
  {

    // Ensure s1 is always the longer sentence (or they are equal in length)
    if (s1.length() < s2.length())
    {
      swap(s1, s2); // Swap if s1 is shorter than s2 to simplify processing
    }

    // Declare two deques to store words from s1 and s2
    deque<string> deq1, deq2;

    // Use stringstream to split sentence s1 into words
    stringstream ss1(s1);
    string token;
    // Extract words from s1 and push them into deq1
    while (ss1 >> token)
    {
      deq1.push_back(token); // Insert each word at the back of deq1
    }

    // Use stringstream to split sentence s2 into words
    stringstream ss2(s2);
    // Extract words from s2 and push them into deq2
    while (ss2 >> token)
    {
      deq2.push_back(token); // Insert each word at the back of deq2
    }

    // Compare and remove matching words from the front of both deques
    while (!deq1.empty() && !deq2.empty() && deq1.front() == deq2.front())
    {
      deq1.pop_front(); // Remove the matching word from the front of deq1
      deq2.pop_front(); // Remove the matching word from the front of deq2
    }

    // Compare and remove matching words from the back of both deques
    while (!deq1.empty() && !deq2.empty() && deq1.back() == deq2.back())
    {
      deq1.pop_back(); // Remove the matching word from the back of deq1
      deq2.pop_back(); // Remove the matching word from the back of deq2
    }

    // If deq2 is empty, it means all words in s2 matched somewhere in s1
    return deq2.empty();
  }
};
