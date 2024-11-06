#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Bubble Sort)
// T.C : O(n^2)
// S.C : O(1)
class Solution
{
public:
  bool canSortArray(vector<int> &nums)
  {
    int n = nums.size(); // Get the size of the array

    // Performance Optimisation
    // Using a Flag to check if any swapping was done in a pass
    bool swapped = true;

    // Perform bubble sort with a condition on swapping
    for (int i = 0; i < n; i++)
    {
      swapped = false; // Reset swap flag for the new pass

      // In each pass, the largest element moves to its correct position at the end
      for (int j = 0; j < n - i - 1; j++)
      {
        // Check if the current element is greater than the next element
        if (nums[j] <= nums[j + 1])
        {
          // No swap needed if nums[j] is already <= nums[j+1], just continue
          continue;
        }
        else
        {
          // If nums[j] > nums[j+1], check if swapping is allowed based on condition
          // Only swap if both elements have the same number of 1-bits in binary representation
          // __builtin_popcount() used to check the bit count of the number
          if (__builtin_popcount(nums[j]) == __builtin_popcount(nums[j + 1]))
          {
            // Swap the elements
            swap(nums[j], nums[j + 1]);
            // Set the swap flag to true
            swapped = true;
          }
          else
          {
            // If elements can't be swapped due to different 1-bit counts, sorting is impossible hence return false
            return false;
          }
        }
      }

      // If no swaps were done in this pass, the array is already sorted
      if (swapped == false)
      {
        // No more passes needed, exit loop
        break;
      }
    }

    // If all passes complete without issue, return true (array can be sorted)
    return true;
  }
};
