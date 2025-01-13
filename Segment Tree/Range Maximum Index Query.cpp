#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + log(n) * Q)
// - O(n): for building the segment tree, where n is the size of the array
// - O(log n):  At each level of recursion, we process one segment, which takes O(log n) time due to the binary structure of the segment tree
// - O(Q):  numebr of queries to perform on the segment tree

//  Space Complexity: O(4*n) for the segment tree array
// - The segment tree stores at most 4 times the size of the array, resulting in O (n) space

class Solution
{
public:
  /**
   * @brief Recursively builds the segment tree that stores the index of the maximum element in each segment
   *
   * @param i The index of the current node in the segment tree
   * @param l The left index of the current range
   * @param r The right index of the current range
   * @param segTree The segment tree array which stores indices of maximum elements
   * @param arr The input array of integers from which the segment tree is built
   */
  void buildSegTree(int i, int l, int r, int segTree[], vector<int> &arr)
  {
    // Base Case: When the range is a single element, store its index
    if (l == r)
    {
      segTree[i] = l; // Store the index of the element, not the element itself
      return;
    }

    // Recursively divide the range and construct left and right subtrees
    int mid = l + (r - l) / 2;
    buildSegTree(2 * i + 1, l, mid, segTree, arr);     // Left child
    buildSegTree(2 * i + 2, mid + 1, r, segTree, arr); // Right child

    // Get the indices of the maximum elements from the left and right children
    int leftIndex = segTree[2 * i + 1];
    int rightIndex = segTree[2 * i + 2];

    // Method 1: Compare values directly using if-else
    if (arr[leftIndex] >= arr[rightIndex])
    {
      segTree[i] = leftIndex; // If left is greater or equal, store left index
    }
    else
    {
      segTree[i] = rightIndex; // Otherwise, store right index
    }

    // Method 2: Use a ternary operator to store the index of the maximum element
    segTree[i] = (arr[segTree[2 * i + 1]] >= arr[segTree[2 * i + 2]]) ? segTree[2 * i + 1] : segTree[2 * i + 2];
  }

  /**
   * @brief Constructs the segment tree from the given array
   *
   * @param arr The input array of integers
   * @param n The size of the input array
   * @return int* Pointer to the segment tree array
   */
  int *constructST(vector<int> &arr, int n)
  {
    // Create a new segment tree array with enough space for 4 times the input array size
    int *segTree = new int[4 * n];
    buildSegTree(0, 0, n - 1, segTree, arr); // Call the recursive function to build the tree
    return segTree;                          // Return the constructed segment tree
  }

  /**
   * @brief Queries the segment tree to find the index of the maximum element in the range [start, end]
   *
   * @param start The start index of the query range
   * @param end The end index of the query range
   * @param i The index of the current node in the segment tree
   * @param l The left index of the current range
   * @param r The right index of the current range
   * @param segTree The segment tree array that stores indices of maximum elements
   * @param arr The input array of integers
   * @return int The index of the maximum element in the range [start, end]
   */
  int querysegTree(int start, int end, int i, int l, int r, int segTree[], vector<int> &arr)
  {
    // Out-of-bound condition
    if (l > end || r < start)
    {
      return -1; // Return -1 for out-of-bound queries
    }

    // If the current range is fully within the query range, return the index of the maximum element
    if (l >= start && r <= end)
    {
      return segTree[i]; // Return the index of the maximum element in the current range
    }

    // Recursively query the left and right children
    int mid = l + (r - l) / 2;
    int leftIndex = querysegTree(start, end, 2 * i + 1, l, mid, segTree, arr);      // Left child query
    int rightIndex = querysegTree(start, end, 2 * i + 2, mid + 1, r, segTree, arr); // Right child query

    // Handle cases where one side of the query is out of bounds
    if (leftIndex == -1)
      return rightIndex;
    if (rightIndex == -1)
      return leftIndex;

    // Compare the elements at the indices and return the index of the maximum element
    return (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
  }

  /**
   * @brief Finds the index of the maximum element in the range [a, b]
   *
   * @param st The segment tree array storing indices of maximum elements
   * @param arr The input array of integers
   * @param n The size of the array
   * @param a The start index of the range
   * @param b The end index of the range
   * @return int The index of the maximum element in the range [a, b]
   */
  int RMIQ(int st[], vector<int> &arr, int n, int a, int b)
  {
    return querysegTree(a, b, 0, 0, n - 1, st, arr); // Query the segment tree for the maximum element index
  }

  /**
   * @brief Handles multiple range maximum index queries and returns the results
   *
   * @param arr The input array of integers
   * @param queries A 2D vector where each query is a pair of integers [a, b] representing the range
   * @return vector<int> A vector of indices corresponding to the maximum elements in each query range
   */
  vector<int> rangeMaximumIndexQuery(vector<int> &arr, vector<vector<int>> &queries)
  {
    int n = arr.size();                 // Size of the input array
    int *segTree = constructST(arr, n); // Construct the segment tree

    vector<int> result; // To store the result of each query
    for (auto &query : queries)
    {
      int a = query[0]; // Start index of the range
      int b = query[1]; // End index of the range

      // Get the index of the maximum element in the range [a, b]
      int idx = RMIQ(segTree, arr, n, a, b);
      result.push_back(idx); // Add the result to the final output
    }
    return result; // Return the results of all queries
  }
};
