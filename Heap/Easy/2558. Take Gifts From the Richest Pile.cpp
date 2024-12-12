#include <bits/stdc++.h>
using namespace std;

// Approach: Using max-heap
// Time Complexity (T.C): O(n + k * log(n))
// Space Complexity (S.C): O(n)
class Solution
{
public:
  long long pickGifts(vector<int> &gifts, int k)
  {
    // Initialize the sum of all gifts initially
    // This step computes the initial sum of all elements in the array
    long long initialSum = 0;
    int n = gifts.size(); // Number of gifts

    // Calculate the initial sum of the gift array
    // O(n) time complexity
    for (int i = 0; i < n; i++)
    {
      initialSum += gifts[i];
    }

    // Create a max-heap (priority queue with default comparator)
    // Heapify operation has O(n) time complexity when using a range of elements
    priority_queue<int> maxHeap(gifts.begin(), gifts.end());

    // Initialize the sum of values "removed" (difference between max and its square root)
    long long mySum = 0;

    // Process `k` largest elements
    while (k--) // O(K)
    {
      // Extract the largest element from the max-heap
      int maxElement = maxHeap.top(); // O(1)
      maxHeap.pop();                  // O(N) pop takes size of Heap Time

      // Compute the remaining value after applying the square root
      // O(logn) T.C
      int remaining = sqrt(maxElement);

      // Push the new value back into the heap
      maxHeap.push(remaining); // O(N) push takes size of Heap Time

      // Add the difference between the original value and the reduced value to `mySum`
      mySum += maxElement - remaining;
    }

    // The final result is the initial sum minus the accumulated difference
    return initialSum - mySum;
  }
};
