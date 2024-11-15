#include <bits/stdc++.h>
using namespace std;

// Simple Two Pointer Approach
// Time Complexity (T.C): O(n) - Each element is visited at most once inside the while loop
// Space Complexity (S.C): O(1) - No extra space used apart from variables

class Solution
{
public:
  int findLengthOfShortestSubarray(vector<int> &arr)
  {
    int n = arr.size(); // Length of the array
    int j = n - 1;      // Initialize the second pointer at the end of the array
    int del;            // Variable to store the length of the subarray to delete

    // Step 1: Find the last position of the `j` pointer
    // Traverse from the end to find the first position where the array is not non-decreasing
    while (j > 0 && arr[j] >= arr[j - 1])
    {
      j--;
    }

    int i = 0;      // Initialize the first pointer at the start of the array
    int result = j; // Initialize the result with the current value of `j` (worst case)

    // Step 2: Find the shortest subarray to delete
    // Use the two pointers `i` and `j` to check valid sub arrays
    while (i < j && (i == 0 || arr[i] >= arr[i - 1]))
    {
      // Ensure `arr[j] >= arr[i]` to maintain the sorted order
      while (j < n && arr[j] < arr[i])
      {
        j++;
      }

      // Calculate the length of the subarray to delete
      del = j - i - 1;

      // Update the result with the minimum length found
      result = min(result, del);

      // Increment the `i` pointer
      i++;
    }

    // Return the minimum length of the subarray to delete
    return result;
  }
};
