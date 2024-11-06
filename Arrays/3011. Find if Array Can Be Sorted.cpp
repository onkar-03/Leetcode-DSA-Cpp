#include <bits/stdc++.h>
using namespace std;

// Approach-1 (Using Bubble Sort)
// We are modifying the Input here be aware of that, if we dont want that take the input in another array and work on that
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

// Approach-2 (Using simple segment sorting check)
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
  bool canSortArray(vector<int> &nums)
  {
    // Initialize variables for the current segment

    // Track the number of 1-bits in the binary representation of the segment
    int numOfSetBits = __builtin_popcount(nums[0]);
    // Track the maximum value in the current segment
    int maxOfSegment = nums[0];
    // Track the minimum value in the current segment
    int minOfSegment = nums[0];

    // Track the maximum of the previous segment for comparison
    int maxOfPrevSegment = INT_MIN; 

    // Traverse through the array starting from the second element
    for (int i = 1; i < nums.size(); i++)
    {
      // Check if the current element has the same number of 1-bits as the current segment
      if (__builtin_popcount(nums[i]) == numOfSetBits)
      {
        // If true, it belongs to the same segment
        // Update the maximum of the current segment
        maxOfSegment = max(maxOfSegment, nums[i]);

        // Update the minimum of the current segment
        minOfSegment = min(minOfSegment, nums[i]);
      }
      else
      {
        // The current element belongs to a new segment
        // Ensure the minimum of the current segment is greater than the max of the previous segment
        if (minOfSegment < maxOfPrevSegment)
        {
          // If not, the array cannot be sorted according to the rules
          return false;
        }

        // Update the max of the previous segment to the max of the current segment
        maxOfPrevSegment = maxOfSegment;
        
        // Start a new segment with the current element
        maxOfSegment = nums[i];
        minOfSegment = nums[i];
        numOfSetBits = __builtin_popcount(nums[i]); // Update the number of 1-bits for the new segment
      }
    }

    // Final check to ensure proper segment arrangement
    if (minOfSegment < maxOfPrevSegment)
    {
      // If the minimum of the final segment is less than the max of the previous, return false
      return false;
    }

    // If all segments are properly arranged, return true
    return true;
  }
};
