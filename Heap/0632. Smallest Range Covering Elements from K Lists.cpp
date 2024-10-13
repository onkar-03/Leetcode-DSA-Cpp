#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using vector of indexes)
// T.C : O(n*k): O(n): Iterate over all elements, O(k): Take out Min & Max Elements
// S.C : O(k) : Used to Store the K Lists given to us
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

// Approach-2 (Using heap)
// T.C : O(n*log(k))
// S.C : O(k)
class Solution
{
public:
  vector<int> smallestRange(vector<vector<int>> &nums)
  {
    // Get the number of lists (k)
    int k = nums.size();

    // Min-heap (priority_queue) to store elements and their positions in the form of vectors
    // Each element in the heap is a vector containing {value, list index, element index}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // Initialize the maximum element encountered in the current window
    int maxElement = INT_MIN;

    // Insert the first element of each list into the heap
    for (int i = 0; i < k; i++)
    {
      // Push {element, list index, element index} for the first element of each list
      pq.push({nums[i][0], i, 0});

      // Update maxElement with the maximum of the first elements of all lists
      maxElement = max(maxElement, nums[i][0]);
    }

    // Initialize the result range with very large values
    // (so that any valid range found will be smaller than this).
    vector<int> resultRange = {-1000000, 1000000};

    // Process the elements in the heap to find the smallest range
    while (!pq.empty())
    {
      // Get the smallest element (the root of the min-heap)
      vector<int> current = pq.top();
      pq.pop();

      // minElement is the smallest element currently in the heap
      int minElement = current[0];

      // listIndex is the index of the list from which minElement came
      int listIndex = current[1];

      // elementIndex is the index of the element in that list
      int elementIndex = current[2];

      // Check if the current range (maxElement - minElement) is smaller than the previous best range
      if (maxElement - minElement < resultRange[1] - resultRange[0])
      {
        // Update resultRange with the current smaller range
        resultRange[0] = minElement;
        resultRange[1] = maxElement;
      }

      // Move to the next element in the list from which the minElement came
      if (elementIndex + 1 < nums[listIndex].size())
      {
        // Get the next element from the same list
        int nextElement = nums[listIndex][elementIndex + 1];

        // Push the next element into the min-heap, along with its list and element indices
        pq.push({nextElement, listIndex, elementIndex + 1});

        // Update maxElement to be the maximum of the current maxElement and the nextElement
        maxElement = max(maxElement, nextElement);
      }
      else
      {
        // If the list has no more elements, stop the process
        // since we can no longer include all lists in the range
        break;
      }
    }

    // Return the smallest range found
    return resultRange;
  }
};
