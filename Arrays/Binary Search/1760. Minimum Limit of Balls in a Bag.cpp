#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Helper function to check if it is possible to make all elements in nums <= mid
  // using at most maxOps operations.
  bool isPossible(vector<int> &nums, int maxOps, int mid)
  {
    int totalOps = 0; // Keeps track of the total operations needed.

    // Iterate through each number in nums.
    for (int &num : nums)
    {
      // Calculate the number of operations needed to reduce `num` to `mid` or less.
      int ops = num / mid;

      // If num is exactly divisible by mid, we need one less operation.
      if (num % mid == 0)
      {
        ops -= 1;
      }

      // Accumulate the operations.
      totalOps += ops;
    }

    // Check if the total operations needed is within the allowed maxOps.
    return totalOps <= maxOps;
  }

  int minimumSize(vector<int> &nums, int maxOperations)
  {
    // Left boundary of the binary search, the smallest possible size of a bag.
    int l = 1;

    // Right boundary of the binary search, the maximum element in nums.
    int r = *max_element(begin(nums), end(nums));

    // Variable to store the result (minimized maximum size of a bag).
    int result = r;

    // Perform binary search to find the minimum possible value of the largest bag.
    while (l <= r)
    {
      int mid = l + (r - l) / 2; // Calculate the middle value.

      // If it is possible to make all elements <= mid with the given maxOps:
      if (isPossible(nums, maxOperations, mid))
      {
        result = mid; // Update the result with the current mid.
        r = mid - 1;  // Move to the left half to minimize further.
      }
      else
      {
        l = mid + 1; // Otherwise, move to the right half.
      }
    }

    return result; // Return the minimized maximum size of the bag.
  }
};
