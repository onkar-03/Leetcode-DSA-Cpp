#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Brute Force : TLE)
// T.C : Constructor: O(n), where n is the length of the nums array
//       Update: O(1), sumRange: O(n)
// S.C : O(n)
class NumArray
{
public:
  vector<int> num; // Stores the array elements
  int n;           // Size of the input array

  /**
   * @brief Constructor to initialize the NumArray object.
   * @param nums Input array for initialization.
   * The array is copied to a member variable for future updates and queries.
   */
  NumArray(vector<int> &nums)
  {
    num = nums;      // Copy the input array to the member variable
    n = nums.size(); // Store the size of the input array
  }

  /**
   * @brief Updates an element in the array.
   * @param index Index in the array to update.
   * @param val New value to set at the given index.
   * Updates the value of the array at the given index.
   */
  void update(int index, int val)
  {
    num[index] = val; // Directly update the value in the array
  }

  /**
   * @brief Calculates the sum of elements in a given range [left, right].
   * @param left Start index of the range.
   * @param right End index of the range.
   * @return Sum of elements in the range [left, right].
   * Uses a simple loop to calculate the sum, resulting in O(n) complexity.
   */
  int sumRange(int left, int right)
  {
    int sum = 0; // Initialize sum to 0
    for (int i = left; i <= right; i++)
    {
      // Iterate through the range
      // Add each element in the range to the sum
      sum += num[i];
    }
    return sum; // Return the calculated sum
  }
};

// Approach-2 (Segment Tree)
// T.C : Constructor: O(n), where n is length of nums array
//       Update, sumRange: O(logN)
// S.C : O(n)
class NumArray
{
public:
  int n;               // Size of the input array
  vector<int> segTree; // Segment Tree to store range sums

  /**
   * @brief Builds the Segment Tree from the input array.
   * @param i Current node index in the Segment Tree.
   * @param l Start index of the range represented by the current node.
   * @param r End index of the range represented by the current node.
   * @param nums Input array used to construct the Segment Tree.
   */
  void buildSegTree(int i, int l, int r, vector<int> &nums)
  {
    if (l == r)
    {                       // Leaf node case
      segTree[i] = nums[l]; // Store the value of the array element
      return;
    }
    int mid = l + (r - l) / 2; // Calculate the middle index

    // Recursively build the left and right subtrees
    buildSegTree(2 * i + 1, l, mid, nums);     // Left child
    buildSegTree(2 * i + 2, mid + 1, r, nums); // Right child

    // Combine the results of the left and right subtrees
    segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
  }

  /**
   * @brief Updates a value in the Segment Tree.
   * @param index Index in the input array to update.
   * @param val New value to update at the given index.
   * @param i Current node index in the Segment Tree.
   * @param l Start index of the range represented by the current node.
   * @param r End index of the range represented by the current node.
   */
  void updateSegTree(int index, int val, int i, int l, int r)
  {
    if (l == r)
    {                   // Leaf node case
      segTree[i] = val; // Update the value
      return;
    }

    int mid = l + (r - l) / 2; // Calculate the middle index

    // Update in the appropriate subtree (left or right)
    if (index <= mid)
    { // If index is in the left subtree
      updateSegTree(index, val, 2 * i + 1, l, mid);
    }
    else
    { // If index is in the right subtree
      updateSegTree(index, val, 2 * i + 2, mid + 1, r);
    }

    // Update the current node by combining the results of the left and right subtrees
    segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
  }

  /**
   * @brief Queries the sum in a range [s, e].
   * @param s Start index of the query range.
   * @param e End index of the query range.
   * @param i Current node index in the Segment Tree.
   * @param l Start index of the range represented by the current node.
   * @param r End index of the range represented by the current node.
   * @return Sum of the elements in the range [s, e].
   */
  int querySegTree(int s, int e, int i, int l, int r)
  {
    if (l > e || r < s)
    { // No overlap
      return 0;
    }

    if (l >= s && r <= e)
    {                    // Complete overlap
      return segTree[i]; // Return the sum stored at this node
    }

    // Partial overlap: query both left and right subtrees
    int mid = l + (r - l) / 2;
    return querySegTree(s, e, 2 * i + 1, l, mid) +
           querySegTree(s, e, 2 * i + 2, mid + 1, r);
  }

  /**
   * @brief Constructor to initialize the NumArray object and build the Segment Tree.
   * @param nums Input array for which the Segment Tree is to be constructed.
   */
  NumArray(vector<int> &nums)
  {
    n = nums.size();                 // Store the size of the input array
    segTree.resize(4 * n);           // Resize the Segment Tree to hold the required number of nodes
    buildSegTree(0, 0, n - 1, nums); // Build the Segment Tree
  }

  /**
   * @brief Updates an element in the array.
   * @param index Index in the input array to update.
   * @param val New value to set at the given index.
   */
  void update(int index, int val)
  {
    updateSegTree(index, val, 0, 0, n - 1); // Start the update from the root node
  }

  /**
   * @brief Calculates the sum of elements in a given range [left, right].
   * @param left Start index of the range.
   * @param right End index of the range.
   * @return Sum of elements in the range [left, right].
   */
  int sumRange(int left, int right)
  {
    return querySegTree(left, right, 0, 0, n - 1); // Start the query from the root node
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums); // Create a NumArray object
 * obj->update(index, val); // Update the element at the given index
 * int param_2 = obj->sumRange(left, right); // Get the sum of elements in the range [left, right]
 */
