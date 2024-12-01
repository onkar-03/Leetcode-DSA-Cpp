#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// Time Complexity (T.C): O(n^2) - Nested loops result in quadratic time complexity.
// Space Complexity (S.C): O(1) - No additional space is used apart from input.
class Solution
{
public:
  // Function to check if there exists two indices `i` and `j` such that:
  // arr[i] == 2 * arr[j] and i != j.
  bool checkIfExist(vector<int> &arr)
  {
    // Get the size of the array
    int n = arr.size();

    // Traverse each element in the array
    for (int i = 0; i < n; i++)
    {
      // Compare the current element with every other element
      for (int j = 0; j < n; j++)
      {
        // Ensure the indices are not the same and check the condition
        if (i != j && arr[i] == 2 * arr[j])
        {
          // Return true if the condition is satisfied
          return true;
        }
      }
    }

    // If no such pair is found, return false
    return false;
  }
};

