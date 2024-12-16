#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force)
// Time Complexity: O(n * k) - For each of the 'k' iterations, we traverse the 'n' elements of the array.
// Space Complexity: O(1) - We do not use any extra space except for variables.
class Solution
{
public:
  // Function to modify the input vector based on the given parameters
  // nums: input vector of integers
  // k: number of iterations
  // multiplier: value by which the minimum element is multiplied
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
  {
    int n = nums.size(); // Get the size of the input vector

    // Perform the operation 'k' times
    for (int j = 0; j < k; j++)
    {
      int idx = 0; // Variable to store the index of the smallest element

      // Find the index of the smallest element in the array
      for (int i = 0; i < n; i++)
      {
        if (nums[i] < nums[idx])
        {
          // If current element is smaller than the one at 'idx'
          // Update 'idx' to the current index
          idx = i;
        }
      }

      // Multiply the smallest element by the given multiplier
      nums[idx] *= multiplier;
    }

    // Return the modified vector after 'k' iterations
    return nums;
  }
};

// Approach-2 (Using std::priority_queue)
// Time Complexity: O(nlogn + k*logn)
// - O(nlogn) for inserting all elements into the priority queue initially.
// - O(k*logn) for performing k operations, where each operation involves removing and adding an element to the priority queue.
// Space Complexity: O(n)
// - The priority queue stores all elements of the array along with their indices.
class Solution
{
public:
// Macro to define a shorthand for pair<int, int> as P
#define P pair<int, int>

  // Function to modify the input vector based on the given parameters
  // nums: input vector of integers
  // k: number of iterations
  // multiplier: value by which the minimum element is multiplied
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
  {
    int n = nums.size(); // Get the size of the input vector

    // Min-heap (priority_queue) to store pairs of (element value, index)
    // The `greater<P>` comparator ensures that the heap is sorted by the smallest element
    priority_queue<P, vector<P>, greater<P>> minHeap;

    // Insert all elements along with their indices into the min-heap
    for (int i = 0; i < n; i++)
    {
      minHeap.push({nums[i], i}); // Push a pair (value, index)
    }

    // Perform the operation 'k' times
    while (k--)
    {
      // Get the smallest element from the heap
      pair<int, int> temp = minHeap.top();
      minHeap.pop(); // Remove it from the heap

      int idx = temp.second;   // Index of the smallest element
      int number = temp.first; // Value of the smallest element

      // Multiply the smallest element by the multiplier
      nums[idx] = number * multiplier;

      // Push the updated value along with its index back into the min-heap
      minHeap.push({nums[idx], idx});
    }

    // Return the modified vector after 'k' iterations
    return nums;
  }
};
