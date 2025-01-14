#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// T.C : O(n^3)
// S.C : O(1)
class Solution
{
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
  {
    int n = A.size(); // Get the size of the input arrays

    // Initialize the result vector with size 'n' and all values set to 0
    vector<int> result(n, 0);

    // Iterate through each prefix index from 0 to n-1
    for (int i = 0; i < n; i++)
    {
      int count = 0; // Counter to store the number of common elements for the current prefix

      // Nested loops to compare elements of prefixes A[0..i] and B[0..i]
      for (int A_i = 0; A_i <= i; A_i++)
      {
        for (int B_i = 0; B_i <= i; B_i++)
        {
          // Check if the current elements from A and B are equal
          if (A[A_i] == B[B_i])
          {
            count++; // Increment the count for a common element
            break;   // Exit the inner loop to avoid counting duplicates
          }
        }
      }

      // Store the count of common elements for the current prefix in the result vector
      result[i] = count;
    }

    return result; // Return the result vector containing prefix common element counts
  }
};

// Approach-2 (Better Approach usign Boolean Array)
// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution
{
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
  {
    int n = A.size(); // Get the size of the input arrays

    vector<int> result(n); // Result vector to store the number of common elements for each prefix

    // Boolean vectors to track the presence of numbers in A and B
    vector<bool> isPresentA(n + 1, false); // isPresentA[i] = true means i is present in A
    vector<bool> isPresentB(n + 1, false); // isPresentB[i] = true means i is present in B

    // Iterate through each prefix of the arrays
    for (int i = 0; i < n; i++)
    {
      // Mark the current elements from A and B as present
      isPresentA[A[i]] = true;
      isPresentB[B[i]] = true;

      int count = 0; // Counter to track the number of common elements in the current prefix

      // Check for all possible elements from 1 to n
      for (int num = 1; num <= n; num++)
      {
        // If an element is present in both A and B, increment the count
        if (isPresentA[num] == true && isPresentB[num] == true)
        {
          count++;
        }
      }

      // Store the count of common elements for the current prefix
      result[i] = count;
    }

    return result; // Return the result vector containing prefix common element counts
  }
};

// Approach-3 (Optimal Approach usign map)
// Time Complexity: O(n) - We traverse the arrays A and B once.
// Space Complexity: O(n) - To store elements and their frequencies in the hash map.
class Solution
{
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
  {
    int n = A.size(); // Get the size of the input arrays

    // Result vector to store the number of common elements for each prefix
    vector<int> result(n);

    // Hash map to track the frequency of elements across A and B
    unordered_map<int, int> mp;

    int count = 0; // Counter to store the number of common elements

    // Iterate through each element of the arrays
    for (int i = 0; i < n; i++)
    {
      // Update the frequency of the current element from A
      mp[A[i]]++;
      // It says its a permutation meaning it appears exactly once in each array
      // So if the element appears twice (once in A and once in B), it is a common element
      if (mp[A[i]] == 2)
      {
        count++;
      }

      // Update the frequency of the current element from B
      mp[B[i]]++;
      // If the element appears twice (once in A and once in B), it is a common element
      if (mp[B[i]] == 2)
      {
        count++;
      }

      // Store the count of common elements for the current prefix
      result[i] = count;
    }

    return result; // Return the result vector containing prefix common element counts
  }
};
