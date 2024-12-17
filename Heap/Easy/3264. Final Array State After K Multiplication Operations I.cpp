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

// Approach-2 (Using Min Heap priority_queue)
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
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
  {
    // Get the size of the input vector
    int n = nums.size();

    // Min-heap (priority_queue) to store pairs of (element value, index)
    priority_queue<P, vector<P>, greater<P>> minHeap;

    // Insert all elements along with their indices into the min-heap
    for (int i = 0; i < n; i++) // O(N)
    {
      // Push a pair (value, index) O(Log N)
      minHeap.push({nums[i], i});
    }

    // Perform the operation 'k' times
    while (k--) // O(K)
    {
      // Get the smallest element from the heap
      pair<int, int> temp = minHeap.top();

      // Remove it from the heap T.C: O(Log N)
      minHeap.pop();

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

// Approach-3 (Using vector as heap for O(n) heapify)
// Time Complexity: O(n + k * logn)
// - O(n) for building the heap initially using `make_heap`.
// - O(k * logn) for k operations, where each operation involves popping and pushing elements into the heap.
// Space Complexity: O(n)
// - The vector `vec` stores all elements of the array as pairs of value and index.
class Solution
{
public:
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
  {
    // Get the size of the input vector
    int n = nums.size();

    // Create a vector of pairs (value, index) to store elements along with their indices
    vector<pair<int, int>> vec(n);

    // Initialize the vector with the array elements and their indices
    for (int i = 0; i < n; i++)
    {
      vec[i] = {nums[i], i}; // Pair each value with its index
    }

    // Build a min-heap from the vector using `make_heap` with `greater<>` comparator
    make_heap(vec.begin(), vec.end(), greater<pair<int, int>>());

    // Perform the operation 'k' times
    while (k--)
    {
      // Remove the smallest element from the heap

      // Move the smallest element to the end of the vector
      pop_heap(begin(vec), end(vec), greater<pair<int, int>>());

      // Extract the smallest element (value, index)
      pair<int, int> temp = vec.back();

      // Remove it from the vector
      vec.pop_back();

      // Retrieve the index and value of the smallest element
      int idx = temp.second;   // Index of the smallest element
      int number = temp.first; // Value of the smallest element

      // Multiply the smallest element by the multiplier
      nums[idx] = number * multiplier;

      // Add the updated element back into the heap
      // Push the updated pair (value, index) to the vector
      vec.push_back({nums[idx], idx});

      // Re-heapify to maintain the min-heap property
      push_heap(begin(vec), end(vec), greater<pair<int, int>>());
    }

    // Return the modified vector after 'k' iterations
    return nums;
  }
};

// Approach-4 (Using vector as heap for O(n) heapify with priority_queue)
// Time Complexity: O(n + k * logn)
// - O(n) for building the heap initially using `make_heap`.
// - O(k * logn) for k operations, where each operation involves popping and pushing elements into the heap.
// Space Complexity: O(n)
// - The vector `vec` stores all elements of the array as pairs of value and index.
class Solution
{
public:
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
  {
    // Get the size of the input vector
    int n = nums.size();

    // Create a vector of pairs (value, index) to store elements along with their indices
    vector<pair<int, int>> vec(n);

    // Initialize the vector with the array elements and their indices
    for (int i = 0; i < n; i++)
    {
      vec[i] = {nums[i], i}; // Pair each value with its index
    }

    // Build a min-heap from the vector using priority_queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq(begin(vec), end(vec));

    // Perform the operation 'k' times
    while (k--)
    {
      // Extract the smallest element from the priority queue
      pair<int, int> temp = pq.top();
      pq.pop(); // Remove the smallest element from the heap

      // Retrieve the index and value of the smallest element
      int idx = temp.second;   // Index of the smallest element
      int number = temp.first; // Value of the smallest element

      // Multiply the smallest element by the multiplier
      nums[idx] = number * multiplier;

      // Push the updated element back into the priority queue
      pq.push({nums[idx], idx});
    }

    // Return the modified vector after 'k' iterations
    return nums;
  }
};
