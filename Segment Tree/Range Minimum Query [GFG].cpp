#include <bits/stdc++.h>
using namespace std;

/**
 * Function to build the segment tree.
 *
 * @param i       Current index in the segment tree.
 * @param l       Left bound of the current segment.
 * @param r       Right bound of the current segment.
 * @param SegTree The segment tree array that stores the computed range minima.
 * @param arr     The input array for which the segment tree is being built.
 */
void buildTree(int i, int l, int r, int segTree[], int arr[])
{
  // Base case: If the range is a single element, store the element in the segment tree
  if (l == r)
  {
    // Assign the value from the input array to the segment tree at index i and return
    segTree[i] = arr[l];
    return;
  }

  // Calculate the midpoint of the current range to split it into two halves
  int mid = l + (r - l) / 2;

  // Recursively build the left and right child subtrees
  buildTree(2 * i + 1, l, mid, segTree, arr);     // Left child
  buildTree(2 * i + 2, mid + 1, r, segTree, arr); // Right child

  // After the left and right subtrees are built, compute the minimum value for the current node
  segTree[i] = min(segTree[2 * i + 1], segTree[2 * i + 2]);
}

/**
 * Function to construct the segment tree.
 *
 * @param arr The input array for which the segment tree is being built.
 * @param n   The size of the input array.
 * @return    The pointer to the segment tree array.
 */
int *constructST(int arr[], int n)
{
  // Allocate memory for the segment tree (size 4 * n)
  int *segTree = new int[4 * n];

  // Build the segment tree using the helper function
  buildTree(0, 0, n - 1, segTree, arr);

  // Return the constructed segment tree
  return segTree;
}

/**
 * Function to query the range minimum in the segment tree.
 *
 * @param s       Start index of the range to query.
 * @param e       End index of the range to query.
 * @param i       Current index in the segment tree.
 * @param l       Left bound of the current segment.
 * @param r       Right bound of the current segment.
 * @param segTree The segment tree array.
 * @return        The minimum value in the range [s, e].
 */
int query(int s, int e, int i, int l, int r, int segTree[])
{
  // If the current range is disjoint from the query range, return infinity (no overlap)
  if (r < s || l > e)
  {
    return INT_MAX;
  }

  // If the current range is fully within the query range, return the value at the current node
  if (l >= s && r <= e)
  {
    return segTree[i];
  }

  // If there's partial overlap, recursively query the left and right child subtrees
  int mid = l + (r - l) / 2;
  return min(query(s, e, 2 * i + 1, l, mid, segTree), query(s, e, 2 * i + 2, mid + 1, r, segTree));
}

/**
 * Function to find the minimum element in a range.
 *
 * @param st    The segment tree array.
 * @param n     The size of the input array.
 * @param a     The start index of the range.
 * @param b     The end index of the range.
 * @return      The minimum value in the range [a, b].
 */
int RMQ(int st[], int n, int a, int b)
{
  // Call the query function to find the minimum in the range [a, b]
  return query(a, b, 0, 0, n - 1, st);
}
