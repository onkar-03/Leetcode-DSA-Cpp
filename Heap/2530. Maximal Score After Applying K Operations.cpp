#include <bits/stdc++.h>
using namespace std;

// Approach (standard heap approach)
// T.C : O(n + k*logn) O(n) during Heapify and k*logn for Pushing Elements into the Heap
// S.C : O(k)
class Solution
{
public:
  long long maxKelements(vector<int> &nums, int k)
  {
    // Initialize a variable 'sum' to hold the total sum of the selected elements.
    long long sum = 0;

    // Create a max heap (priority queue) to efficiently extract the largest elements.
    // O(n) time complexity for Heapifying the vector 'nums' initially.
    // After that it takes (Log n) time only to push elements
    priority_queue<int> pq(nums.begin(), nums.end());

    // Repeat the process 'k' times to extract and modify the largest element.
    while (k--)
    {
      // Get the largest element from the heap (the top of the priority queue).
      int maxElement = pq.top();

      // Remove the largest element from the heap.
      pq.pop();

      // Add the largest element to the sum.
      sum += maxElement;

      // Reduce the largest element by dividing it by 3, rounding up to the nearest integer using 'ceil'.
      maxElement = ceil(maxElement / 3.0);

      // Push the reduced element back into the heap for future consideration.
      pq.push(maxElement);
    }

    // Return the total sum after 'k' iterations.
    return sum;
  }
};
