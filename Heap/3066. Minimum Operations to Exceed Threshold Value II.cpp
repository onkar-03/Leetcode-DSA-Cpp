#include <bits/stdc++.h>
using namespace std;

/*
 * Approach-1: Using MinHeap
 * - Use a min-heap (priority queue) to always combine the two smallest
 * elements.
 * - Keep combining the smallest two elements until the top element is >= k.
 * - Each operation: pick the two smallest, merge them, and push back.
 * - Stop when the smallest element is at least k.
 * ----------------------------
 * T.C: O(n log n)
 * - Heap initialization takes O(n).
 * - Each operation (pop + push) is O(log n), and at worst, we perform O(n)
 * operations.
 * - Thus, the overall complexity is O(n log n).
 * ----------------------------
 * S.C: O(n)
 * - We store all elements in a min-heap, which requires O(n) space.
 */

class Solution
{
public:
  int minOperations(vector<int> &nums, int k)
  {
    int n = nums.size(); // Get the size of the array
    int count = 0;       // Initialize the operation count

    // If there are fewer than 2 elements, we can't perform operations
    if (n < 2)
    {
      return -1;
    }

    // Min Heap Heapify -> Logn
    priority_queue<long, vector<long>, greater<long>> pq(begin(nums),
                                                         end(nums));

    while (!pq.empty() && pq.top() < k)
    {
      // Get the smallest element
      long smallestFirst = pq.top();

      // Remove the smallest element
      pq.pop();

      // Get the next smallest element
      long smallestSecond = pq.top();

      // Remove the second smallest element
      pq.pop();

      // Combine the two smallest elements and push the new element back
      // into the heap
      pq.push((smallestFirst * 2 + smallestSecond));

      count++; // Increment the operation count
    }

    return count; // Return the total number of operations performed
  }
};
