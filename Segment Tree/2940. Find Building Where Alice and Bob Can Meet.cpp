#include <bits/stdc++.h>
using namespace std;

// Approach: Segment Tree Range Maximum Query + Binary Search
// Time Complexity: O(n + q * (log n)^2)
// - Building the segment tree: O(n)
// - For each query:
//   - Binary search over the range [l, r]: O(log n)
//   - For each step in the binary search, a segment tree query is performed: O(log n)
//   - Combined complexity per query: O((log n)^2)
// - Total for q queries: O(n + q * (log n)^2)

// Space Complexity: O(N)
// - Segment tree storage: O(n)
class Solution
{
public:
  // Function to build the segment tree to find the index of the maximum value
  void buildSegmentTree(int i, int l, int r, int segmentTree[], vector<int> &heights)
  {
    if (l == r)
    {
      // Base case: leaf node represents a single element
      segmentTree[i] = l; // Store the index of the current element
      return;
    }

    // Divide the range into two halves
    int mid = l + (r - l) / 2;
    buildSegmentTree(2 * i + 1, l, mid, segmentTree, heights);     // Left child
    buildSegmentTree(2 * i + 2, mid + 1, r, segmentTree, heights); // Right child

    // Get indices of maximum elements in the left and right halves
    int leftIndex = segmentTree[2 * i + 1];
    int rightIndex = segmentTree[2 * i + 2];

    // Store the index of the larger element between the two children
    segmentTree[i] = (heights[leftIndex] >= heights[rightIndex])
                         ? leftIndex
                         : rightIndex;
  }

  // Function to initialize the segment tree
  int *constructST(vector<int> &heights, int n)
  {
    // Create a segment tree with size 4 * n to accommodate the range
    int *segmentTree = new int[4 * n];
    buildSegmentTree(0, 0, n - 1, segmentTree, heights); // Build the tree
    return segmentTree;                                  // Return the constructed segment tree
  }

  // Function to query the maximum value index in a given range [start, end]
  int querySegmentTree(int start, int end, int i, int l, int r, int segmentTree[], vector<int> &heights)
  {
    // If the range [l, r] is completely outside [start, end]
    if (l > end || r < start)
    {
      return -1; // Return -1 for out-of-bound queries
    }

    // If the range [l, r] is completely inside [start, end]
    if (l >= start && r <= end)
    {
      return segmentTree[i]; // Return the stored maximum index
    }

    // Split the range and query both halves
    int mid = l + (r - l) / 2;
    int leftIndex = querySegmentTree(start, end, 2 * i + 1, l, mid, segmentTree, heights);
    int rightIndex = querySegmentTree(start, end, 2 * i + 2, mid + 1, r, segmentTree, heights);

    // Handle cases where one half is out of bounds
    if (leftIndex == -1)
      return rightIndex;
    if (rightIndex == -1)
      return leftIndex;

    // Return the index of the larger value
    return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
  }

  // Wrapper function to get the index of the maximum element in the range [a, b]
  int RMIQ(int st[], vector<int> &heights, int n, int a, int b)
  {
    return querySegmentTree(a, b, 0, 0, n - 1, st, heights);
  }

  // Main function to solve the "Leftmost Building Queries" problem
  vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
  {
    int n = heights.size();

    // Construct the segment tree for heights
    int *segmentTree = constructST(heights, n);

    vector<int> result; // To store results for each query
    for (auto &query : queries)
    {
      int minIndex = min(query[0], query[1]);
      int maxIndex = max(query[0], query[1]);

      // Case 1: Both indices are the same
      if (minIndex == maxIndex)
      {
        result.push_back(minIndex);
        continue;
      }

      // Case 2: The height at maxIndex is greater than minIndex
      if (heights[maxIndex] > heights[minIndex])
      {
        result.push_back(maxIndex);
        continue;
      }

      // Case 3: Binary search for the leftmost building meeting the condition
      int l = maxIndex + 1;
      int r = n - 1;
      int resultIndex = INT_MAX;

      while (l <= r)
      {
        int mid = l + (r - l) / 2;

        // Get the index of the maximum element in the range [l, mid]
        int idx = RMIQ(segmentTree, heights, n, l, mid);

        // If the height is greater than both minIndex and maxIndex
        if (heights[idx] > max(heights[minIndex], heights[maxIndex]))
        {
          resultIndex = min(resultIndex, idx); // Update resultIndex
          r = mid - 1;                         // Continue searching on the left
        }
        else
        {
          l = mid + 1; // Continue searching on the right
        }
      }

      // If no valid building was found, push -1; otherwise, push the resultIndex
      if (resultIndex == INT_MAX)
      {
        result.push_back(-1);
      }
      else
      {
        result.push_back(resultIndex);
      }
    }

    return result; // Return the result for all queries
  }
};
