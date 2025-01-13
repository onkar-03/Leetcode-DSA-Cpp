#include <bits/stdc++.h>
using namespace std;

// NOTE - Since this is Range Sum Query, you can simply solve it using Prefix Sum Array as well. But this is segment tree repo, so I have mentioned Segment tree approach

// Using Segment Tree
// Time Complexity: O(q * log(n))
// - Building the segment tree takes O(n) since we visit each node in the tree once
// - For each query, the segment tree is traversed in O(log(n)) due to the height of the tree
// - Total time for q queries: O(q * log(n))

// Space Complexity: O(4 * n)
// - The segment tree requires O(4 * n) space to store nodes, where n is the size of the input array.

class Solution
{
public:
  /**
   * Function to build the segment tree.
   *
   * @param i       Current index in the segment tree.
   * @param l       Left bound of the current segment.
   * @param r       Right bound of the current segment.
   * @param segTree The segment tree vector.
   * @param arr     The input array for which the segment tree is being built.
   */
  void buildSegTree(int i, int l, int r, vector<int> &segTree, int arr[])
  {
    // Base case: if the segment represents a single element
    if (l == r)
    {
      segTree[i] = arr[l]; // Store the array value in the segment tree
      return;
    }

    // Calculate the midpoint of the current segment
    int mid = l + (r - l) / 2;

    // Recursively build the left and right children
    buildSegTree(2 * i + 1, l, mid, segTree, arr);     // Left child
    buildSegTree(2 * i + 2, mid + 1, r, segTree, arr); // Right child

    // Combine the results of the left and right children
    segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
  }

  /**
   * Function to query the sum in a given range [s, e].
   *
   * @param s       Start of the query range (0-based index).
   * @param e       End of the query range (0-based index).
   * @param i       Current index in the segment tree.
   * @param l       Left bound of the current segment.
   * @param r       Right bound of the current segment.
   * @param segTree The segment tree vector.
   * @return        The sum of elements in the range [s, e].
   */
  int query(int s, int e, int i, int l, int r, vector<int> &segTree)
  {
    // Case 1: No overlap between the current segment and query range
    if (l > e || r < s)
    {
      return 0; // Return 0 as this segment doesn't contribute to the sum
    }

    // Case 2: Complete overlap of the current segment with the query range
    if (s <= l && e >= r)
    {
      return segTree[i]; // Return the precomputed sum of this segment
    }

    // Case 3: Partial overlap - recurse into left and right children
    int mid = l + (r - l) / 2; // Calculate the midpoint of the current segment

    // Combine the results from the left and right children
    return query(s, e, 2 * i + 1, l, mid, segTree) + query(s, e, 2 * i + 2, mid + 1, r, segTree);
  }

  /**
   * Function to perform multiple range sum queries on the input array.
   *
   * @param n        Size of the input array.
   * @param arr      Input array.
   * @param q        Number of queries.
   * @param queries  Array containing start and end indices of each query (1-based index).
   * @return         A vector containing the results of all the queries.
   */
  vector<int> querySum(int n, int arr[], int q, int queries[])
  {
    // Step 1: Initialize the segment tree with a size of 4 * n
    vector<int> segTree(4 * n, 0);

    // Step 2: Build the segment tree
    buildSegTree(0, 0, n - 1, segTree, arr);

    // Step 3: Initialize a result vector to store the query results
    vector<int> result;

    // Step 4: Process each query
    for (int i = 0; i < 2 * q; i += 2)
    {
      // Convert 1-based indices to 0-based indices
      int start = queries[i] - 1;
      int end = queries[i + 1] - 1;

      // Query the segment tree for the sum in the range [start, end]
      result.push_back(query(start, end, 0, 0, n - 1, segTree));
    }

    // Step 5: Return the results of all queries
    return result;
  }
};
