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

// Approach-2 (Using Extra Space)
// Time Complexity (T.C): O(n) - Single traversal of the array with efficient lookups in the hash set.
// Space Complexity (S.C): O(n) - Additional space is used for the hash set to store elements.
class Solution
{
public:
  // Function to check if there exists two indices `i` and `j` such that:
  // arr[i] == 2 * arr[j] or arr[j] == 2 * arr[i].
  bool checkIfExist(vector<int> &arr)
  {
    // Get the size of the array
    int n = arr.size();

    // Initialize an unordered set to store elements we have seen so far
    unordered_set<int> st;

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
      // Check if the double of the current element exists in the set
      if (st.find(arr[i] * 2) != st.end())
      {
        return true; // Found a valid pair
      }
      // Check if half of the current element exists in the set (only for even numbers)
      else if (arr[i] % 2 == 0 && st.find(arr[i] / 2) != st.end())
      {
        return true; // Found a valid pair
      }

      // Add the current element to the set
      st.insert(arr[i]);
    }

    // If no valid pair is found, return false
    return false;
  }
};

// Approach-3 (Using Binary Search)
// Time Complexity (T.C): O(nlogn) - Sorting takes O(nlogn), and binary search for each element takes O(logn).
// Space Complexity (S.C): O(1) - Sorting is done in-place, and no additional space is used apart from variables.
class Solution
{
public:
  // Binary Search Function
  int bSearch(vector<int> &arr, int target)
  {
    int l = 0;              // Left pointer
    int r = arr.size() - 1; // Right pointer

    // Perform binary search
    while (l <= r)
    {
      // Calculate mid to avoid overflow
      int mid = l + (r - l) / 2;

      if (arr[mid] == target)
      {
        return mid; // Target found
      }
      else if (arr[mid] > target)
      {
        r = mid - 1; // Narrow the search to the left half
      }
      else
      {
        l = mid + 1; // Narrow the search to the right half
      }
    }

    return -1; // Target not found
  }

  // Main function to check if a number and its double exist in the array
  bool checkIfExist(vector<int> &arr)
  {
    int n = arr.size();

    // Step 1: Sort the array in ascending order
    sort(begin(arr), end(arr));

    // Step 2: Traverse each element in the sorted array
    for (int i = 0; i < n; i++)
    {
      // Use binary search to find 2 * arr[i]
      int j = bSearch(arr, 2 * arr[i]);

      // Ensure the found index is not the same as the current index
      if (j != -1 && j != i)
      {
        return true; // Found a valid pair
      }
    }

    // Return false if no valid pair is found
    return false;
  }
};
