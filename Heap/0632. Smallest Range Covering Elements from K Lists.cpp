#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using vector of indexes)
// T.C : O(n*k)
// S.C : O(k)
class Solution
{
public:
  vector<int> smallestRange(vector<vector<int>> &nums)
  {
    // Get the number of lists (k lists).
    int k = nums.size();

    // Initialize a vector 'vec' of size 'k' with all zeros.
    // This vector will track the current index being checked in each list.
    vector<int> vec(k, 0);

    // Initialize the result range with very large values (outside the possible range of input numbers).
    vector<int> resultRange = {-1000000, 1000000};

    // Infinite loop until we break it when we reach the end of one list.
    while (true)
    {

      // Initialize the minimum element
      int minElement = INT_MAX;
      // Initialize the maximum element
      int maxElement = INT_MIN;

      // Variable to store the index of the list containing the current minimum element.
      int minElementListIndex = 0;

      // Iterate through each list to find the current minimum and maximum elements.
      for (int i = 0; i < k; i++)
      {
        // Get the current list index.
        int listIndex = i;

        // Get the current index in the list we are looking at.
        int elementIndex = vec[i];

        // Get the actual element from the list.
        int element = nums[listIndex][elementIndex];

        // If the current element is smaller than the current minimum, update the minimum.
        if (element < minElement)
        {
          // Update the minimum element.
          minElement = element;
          // Update the index of the list with the minimum element.
          minElementListIndex = listIndex;
        }

        // If the current element is larger than the current maximum, update the maximum.
        if (element > maxElement)
        {
          maxElement = element; // Update the maximum element.
        }
      }

      // Check if the current range (maxElement - minElement) is smaller than the previously recorded range.
      if ((maxElement - minElement) < (resultRange[1] - resultRange[0]))
      {
        resultRange[0] = minElement; // Update the result with the new minimum.
        resultRange[1] = maxElement; // Update the result with the new maximum.
      }

      // Move the pointer (index) in the list that contains the current minimum element to shorten the range.
      int nextIndex = vec[minElementListIndex] + 1; // Increment the index for the list with the smallest element.

      // If we reach the end of the list, we stop the loop (because we can't pick more elements from this list).
      if (nextIndex >= nums[minElementListIndex].size())
      {
        // Stop the loop when we've exhausted one of the lists.
        break;
      }

      // Update the index in 'vec' for the list that had the minimum element, moving it to the next element.
      // Move to the next element in the list that had the minimum element.
      vec[minElementListIndex] = nextIndex;
    }

    // Return the final smallest range that covers at least one element from each list.
    return resultRange;
  }
};
